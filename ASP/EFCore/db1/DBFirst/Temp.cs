using System;
using System.Collections.Generic;

namespace DBFirst;

public partial class Temp
{
    public int? BooksId { get; set; }

    public int? AuthorsId { get; set; }

    public virtual Author? Authors { get; set; }

    public virtual Book? Books { get; set; }
}
