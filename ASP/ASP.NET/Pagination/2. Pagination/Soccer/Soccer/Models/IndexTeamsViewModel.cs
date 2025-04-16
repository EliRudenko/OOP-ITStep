using System.Collections.Generic;

namespace Soccer.Models
{
    public class IndexTeamsViewModel
    {
        public IEnumerable<Teams> Teams { get; }
        public PageViewModel PageViewModel { get; }

        public IndexTeamsViewModel(IEnumerable<Teams> teams, PageViewModel viewModel)
        {
            Teams = teams;
            PageViewModel = viewModel;
        }
    }
}
