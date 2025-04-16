namespace Soccer.Models
{
    public class IndexViewModel
    {
        public IEnumerable<Players> Players { get; }
        public PageViewModel PageViewModel { get; }
        public IndexViewModel(IEnumerable<Players> players, PageViewModel viewModel)
        {
            Players = players;
            PageViewModel = viewModel;
        }
    }
}
