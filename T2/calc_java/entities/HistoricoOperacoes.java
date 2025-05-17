package calculadora.entities;

import java.util.ArrayList;
import java.util.List;

public class HistoricoOperacoes {
    private List<String> operacoes;

    public HistoricoOperacoes() {
        this.operacoes = new ArrayList<>();
    }

    public void adcionarOperacoes(String operacao){
        operacoes.add(operacao);
    }

    public void exibirHistorico(){
        if(operacoes.isEmpty()){
            System.out.println("Historico vazio");
        }
        System.out.println("Historico de operaçoes: ");
        for(int i = 0; i< operacoes.size(); i++){
            System.out.println((i + 1) + ". "+operacoes.get(i));
        }
        }

        public void limparHistorico(){
        operacoes.clear();
            System.out.println("Historico limpo com sucesso");
        }
    }

