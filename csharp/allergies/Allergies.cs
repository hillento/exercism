using System;
using System.Collections.Generic;
using System.Linq;

public enum Allergen
{
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats
}

public class Allergies
{
    private int mask;
    public Allergies(int mask)
    {
        this.mask = mask;
    }

    public bool IsAllergicTo(Allergen allergen)
    {
        if ((this.mask & (1 << (int)allergen)) != 0)
        {
            return true;
        }
        return false;
    }

    public Allergen[] List()
    {
        List<Allergen> r = new List<Allergen>();
        foreach (Allergen a in Enum.GetValues(typeof(Allergen)))
        {
            if (IsAllergicTo(a))
            {
                r.Add(a);
            }
        }
        return r.ToArray();
    }
}
