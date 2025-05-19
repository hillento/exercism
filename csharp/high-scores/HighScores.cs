public class HighScores
{
    List<int> highScores = new List<int>();
    public HighScores(List<int> list)
    {
        highScores = list;
    }

    public List<int> Scores()
    {
        return highScores;
    }

    public int Latest()
    {
        return highScores[highScores.Count - 1];
    }

    public int PersonalBest()
    {
        return highScores.MaxBy(x => x);
    }

    public List<int> PersonalTopThree()
    {
        return highScores.OrderByDescending(x => x).Take(3).ToList();

    }
}
