using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
namespace Livraria
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            txtUserLogin.BackColor = Color.White;
            panel2.BackColor = Color.White;
            panel3.BackColor = SystemColors.Control;
            txtSenhaLogin.BackColor = SystemColors.Control;
        }

        private void textBox2_Click(object sender, EventArgs e)
        {
            txtSenhaLogin.BackColor = Color.White;
            panel3.BackColor = Color.White;
            txtUserLogin.BackColor = SystemColors.Control;
            panel2.BackColor = SystemColors.Control;
        }

        private void pictureBox3_MouseDown(object sender, MouseEventArgs e)
        {
            txtSenhaLogin.UseSystemPasswordChar = false;
        }

        private void pictureBox3_MouseUp(object sender, MouseEventArgs e)
        {
            txtSenhaLogin.UseSystemPasswordChar = true;
        }
       
        private void btnLogin_Click(object sender, EventArgs e)
        {
            ConectaBanco conecta = new ConectaBanco();
               if(conecta.verifica(txtUserLogin.Text,txtSenhaLogin.Text)==true)
            {
                Livraria liv = new Livraria();
                this.Hide();
                liv.ShowDialog();
                this.Close();
            }
            else 
            { 
                MessageBox.Show("Usuário ou senha incorreta" + conecta.mensagem);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
