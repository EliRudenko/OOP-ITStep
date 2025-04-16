using System.Collections.Generic;

namespace Soccer.Models
{
    public class TeamListViewModel
    {
        public IEnumerable<Teams> Teams { get; set; } = new List<Teams>();
        public string? Coach { get; set; }
    }
}
