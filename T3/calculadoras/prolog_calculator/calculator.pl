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