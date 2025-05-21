module Main where

import Calculator
import Text.ParserCombinators.ReadP
import Control.Applicative ((<|>))
import Data.Char

-- Parser de número com ponto e espaços
number :: ReadP Expr
number = do
  skipSpaces
  num <- munch1 (\c -> isDigit c || c == '.')
  skipSpaces
  return (Val (read num))

-- Parênteses com espaço
parens :: ReadP Expr
parens = do
  skipSpaces
  _ <- char '('
  e <- expr
  skipSpaces
  _ <- char ')'
  skipSpaces
  return e

-- Fator: número ou parênteses
factor :: ReadP Expr
factor = number <|> parens

-- Termo com multiplicação e divisão
term :: ReadP Expr
term = chainl1 factor muldiv
  where
    muldiv = do
      skipSpaces
      op <- (char '*' >> return Mul) <|> (char '/' >> return Div)
      skipSpaces
      return op

-- Expressão completa com adição e subtração
expr :: ReadP Expr
expr = chainl1 term addsub
  where
    addsub = do
      skipSpaces
      op <- (char '+' >> return Add) <|> (char '-' >> return Sub)
      skipSpaces
      return op

-- Função para processar a string de entrada
calculate :: String -> Either String Double
calculate input =
  case readP_to_S (expr <* skipSpaces <* eof) input of
    [(parsed, "")] ->
      case eval parsed of
        Just result -> Right result
        Nothing     -> Left "Erro: divisão por zero!"
    _ -> Left "Erro de parsing: expressão inválida."

-- Programa principal
main :: IO ()
main = loop
  where
    loop = do
      putStrLn "Digite uma expressão (ou 'sair' para encerrar):"
      input <- getLine
      if map toLower input `elem` ["sair", "exit"]
        then putStrLn "Encerrando a calculadora. 👋"
        else do
          case calculate input of
            Right result -> putStrLn ("Resultado: " ++ show result)
            Left err     -> putStrLn err
          loop
