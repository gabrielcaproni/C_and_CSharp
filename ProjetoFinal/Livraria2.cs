using System.Data;

namespace Livraria
{
    public partial class Livraria1 : Form
    {
        public Livraria1()
        {
            InitializeComponent();
        }

        void ListaEditora()
        {
            ConectaBanco con = new ConectaBanco();
            DataTable tabelaDados = new DataTable();
            tabelaDados = con.lista_editora();
            cbEditora.DataSource = tabelaDados;
            cbEditora.DisplayMember = "nome";
            cbEditora.ValueMember = "codEditora";
            // preenchendo cbAlteraGenero
            // cbAlteraGenero.DataSource = tabelaDados;
            // cbAlteraGenero.DisplayMember = "genero";
            // cbAlteraGenero.ValueMember = "idgenero";
            //
            lblerro.Text = con.mensagem;
            cbEditora.Text = "";
            //cbAlteraGenero.Text = "";
        }
        void ListaProduto()
        {
            ConectaBanco con = new ConectaBanco();
            dgProdutos.DataSource = con.lista_produto();
        }


        private void Livraria_Load(object sender, EventArgs e)
        {
            listaEditora();
            listaProduto();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void cbGenero_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}