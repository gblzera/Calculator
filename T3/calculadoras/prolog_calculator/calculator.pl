% calculadora achada no stack overflow

% regra de loop
start :-
    write('Digite uma expressão (ou "sair" para encerrar): '), nl,
    read(Input),
    handle_input(Input).

% lida com entrada do usuário
handle_input(sair) :-
    write('Encerrando a calculadora. 👋'), nl.

handle_input(Input) :-
    catch(Result is Input, _, write('Erro: expressão inválida ou divisão por zero.')), !,
    ( number(Result)
    -> write('Resultado> '), write(Result), nl
    ; true
    ),
    start.

% is em prolog não é apenas uma atribuição simples, ele é um avaliador arithmetico automatico.
% a escrita de Result is Input, o prolog: Pega a expressão em Input (exemplo 2+3*4), avalia automaticamente seguindo as regras matematicas e calcula o restulado e unifica com Result.
% Por que não precisa programar +, -, *, /?
% O Prolog já tem essas operações built-in! O is reconhece automaticamente:
% + (adição)
% - (subtração)
% * (multiplicação)
% / (divisão)
% ** (exponenciação)
% mod (módulo)