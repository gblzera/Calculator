module Calculator where

-- Tipo de expressão matemática
data Expr
  = Val Double
  | Add Expr Expr
  | Sub Expr Expr
  | Mul Expr Expr
  | Div Expr Expr
  deriving (Show)

-- Avaliador seguro com Maybe
eval :: Expr -> Maybe Double
eval (Val n)     = Just n
eval (Add x y)   = (+) <$> eval x <*> eval y
eval (Sub x y)   = (-) <$> eval x <*> eval y
eval (Mul x y)   = (*) <$> eval x <*> eval y
eval (Div x y)   = do
  dy <- eval y
  if dy == 0
    then Nothing
    else do
      dx <- eval x
      return (dx / dy)
