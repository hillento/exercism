public static class CollatzConjecture
{
    public static int Steps(int number)
    {
        if (number < 1)
        {
            throw new ArgumentOutOfRangeException();
        }
        int n = 0;
        while (number > 1)
        {
            if (number % 2 == 0)
            {
                number = number / 2;
                n++;
            }
            else
            {
                number = (number * 3) + 1;
                n++;
            }
        }
        return n;
    }
}
