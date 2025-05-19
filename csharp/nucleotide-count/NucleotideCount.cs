public static class NucleotideCount
{


    public static IDictionary<char, int> Count(string sequence)
    {
        IDictionary<char, int> nucleotides = new Dictionary<char, int>()
        {
            {'A',0},
            {'C',0},
            {'G',0},
            {'T',0},
        };
        foreach (char n in sequence)
        {
            if (!nucleotides.ContainsKey(n))
            {
                throw new ArgumentException();
            }
            nucleotides[n]++;
        }
        return nucleotides;
    }
}
