-- Calculadora básica em Lua
function calculadora(operacao, num1, num2)
    if operacao == "+" then
        return num1 + num2
    elseif operacao == "-" then
        return num1 - num2
    elseif operacao == "*" then
        return num1 * num2
    elseif operacao == "/" then
        if num2 == 0 then
            return "Divisão por zero"
        else
            return num1 / num2
        end
    else
        return "Operação inválida"
    end
end

while true do
    -- Exibir o menu
    print("\nCalculadora em Lua")
    print("Digite a opreação (+, -, *, /) ou 'sair' para encerrar:")

    local operacao = io.read()

    if operacao == "sair" then
        print("Encerrando a calculadora...")
        break
    end

    print("Digite o primeiro número:")
    local num1 = tonumber(io.read())

    print("Digite o segundo número:")
    local num2 = tonumber(io.read())

    local resultado = calculadora(operacao, num1, num2)
    print("Resultado: " .. resultado)
end