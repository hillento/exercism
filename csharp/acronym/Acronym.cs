using System.Text.RegularExpressions;

public static class Acronym
{
    public static string Abbreviate(string phrase)
    {
        phrase = phrase.Replace("-", " ");
        phrase = Regex.Replace(phrase, "[^a-zA-Z ]*", "", RegexOptions.Compiled);
        var split = Regex.Split(phrase, " {1,}");


        List<char> acronym = new List<char>();

        foreach (string word in split)
        {
            acronym.Add(Char.ToUpper(word[0]));
        }
        string r = new string(acronym.ToArray());
        return r;
    }
}
