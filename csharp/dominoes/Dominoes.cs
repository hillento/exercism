public static class Dominoes
{
    public static bool CanChain(IEnumerable<(int, int)> dominoes)
    {
        //things to track...
        //1. The first number in the chain
        //2. the last number in the chain
        //3. the pool of dominoes left so ones that don't fit can be tried again
        return tryPermutations(dominoes.ToList(), 0, 0);
    }
    public static bool tryPermutations(List<(int, int)> dominoes, int first, int last)
    {
        //when no omre dominoes are left, ensure it creates the circle
        if (dominoes.Count == 0 && first == last)
            return true;

        //It doesn't matter which domino is first so we don't need to try each one as a first
        for (int i = 0; i < dominoes.Count; i++)
        {
            var (a, b) = dominoes[i];
            // first domino
            if (last == 0)
            {
                first = a;
                last = b;
            }
            //check one side of the domino
            else if (last == a)
                last = b;
            //check the other side on domino
            else if (last == b)
                last = a;
            //no match so move to next iteration
            else
                continue;

            //This will keeps the ones that didn't fit and will try them now that a new one is placed. 
            var copy = new List<(int, int)>(dominoes);
            copy.RemoveAt(i);
            if (tryPermutations(copy, first, last))
                return true;
        }
        return false;
    }
}
