using System;
using System.Collections.Generic;

namespace DBFirst;

public partial class Student
{
    public int Id { get; set; }

    public string Name { get; set; } = null!;

    public int? Age { get; set; }

    public int? IdGroups { get; set; }

    public virtual Group? IdGroupsNavigation { get; set; }
}
