using System.Collections.Generic;

public static class MatchingBrackets
{
    public static bool IsPaired(string input)
    {
        Stack<char> stack = new Stack<char>();
        string brackets = "()[]{}";
        foreach (char b in input)
        {
            if (!brackets.Contains(b)) { continue; }
            if (b == '[' || b == '{' || b == '(')
            {
                stack.Push(b);
                continue;
            }
            if (stack.Count == 0) { return false; }
            char last = stack.Peek();
            if ((b == ']' && last == '[') || (b == ')' && last == '(') || (b == '}' && last == '{'))
            {
                stack.Pop();
                continue;
            }
            return false;
        }
        return stack.Count == 0;
    }
}
