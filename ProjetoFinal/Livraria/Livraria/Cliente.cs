using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Livraria
{
    internal class Cliente
    {
        string nome, dataNascimento, cpf, uf, endereco, bairro, cidade, cep, email;
        public string Nome { get => nome; set => nome = value; }
        public string DataNascimento { get => dataNascimento; set => dataNascimento = value; }
        public string CPF { get => cpf; set => cpf = value; }
        public string UF { get => uf; set => uf = value; }
        public string Endereco { get => endereco; set => endereco = value; }
        public string Bairro { get => bairro; set => bairro = value; }
        public string Cidade { get => cidade; set => cidade = value; }
        public string CEP { get => cep; set =>  cep = value; }
        public string Email { get => email; set => email = value; }



    }
}
