public class GradeSchool
{
    Dictionary<string, int> roster = new Dictionary<string, int>();
    public bool Add(string student, int grade) => roster.TryAdd(student, grade);

    public IEnumerable<string> Roster() => roster.OrderBy(x => x.Value).ThenBy(x => x.Key).Select(x => x.Key);

    public IEnumerable<string> Grade(int grade) => roster.Where(x => x.Value == grade).OrderBy(x => x.Key).Select(x => x.Key);
}
