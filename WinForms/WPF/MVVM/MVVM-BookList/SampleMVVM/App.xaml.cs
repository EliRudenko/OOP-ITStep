using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Json;
using System.Windows;
using SampleMVVM.Models;
using SampleMVVM.ViewModels;
using SampleMVVM.Views;

namespace SampleMVVM
{
    public partial class App : Application
    {

        private void OnStartup(object sender, StartupEventArgs e)
        {
            ListBook listBook = new ListBook();
            listBook.LoadFromFile(); 

            MainView view = new MainView();
            MainViewModel viewModel = new MainViewModel(listBook.GetBooks());
            view.DataContext = viewModel;
            view.Show();
        }



    }
}
