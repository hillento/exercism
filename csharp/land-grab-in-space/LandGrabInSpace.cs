using System;
using System.Collections.Generic;
using System.Linq;

public struct Coord
{
    public Coord(ushort x, ushort y)
    {
        X = x;
        Y = y;
    }

    public ushort X { get; }
    public ushort Y { get; }
}

public struct Plot
{

    public Plot(Coord i, Coord ii, Coord iii, Coord iv)
    {
        coordA = i;
        coordB = ii;
        coordC = iii;
        coordD = iv;
        longest = LongestSide(coordA, coordB, coordC, coordD);
    }

    public Coord coordA { get; }
    public Coord coordB { get; }
    public Coord coordC { get; }
    public Coord coordD { get; }
    public double longest { get; }

    public static double LongestSide(Coord coordA, Coord coordB, Coord coordC, Coord coordD)
    {
        //pythagorean
        var sides = new double[4];
        sides[0] = segmentLenSqrd(coordA, coordB);
        sides[1] = segmentLenSqrd(coordB, coordC);
        sides[2] = segmentLenSqrd(coordC, coordD);
        sides[3] = segmentLenSqrd(coordD, coordA);
        return sides.Max();
    }

    private static double segmentLenSqrd(Coord coordA, Coord coordB) => Math.Pow(coordA.X - coordB.X, 2) + Math.Pow(coordA.Y - coordB.Y, 2);
}


public class ClaimsHandler
{
    List<Plot> claims = new List<Plot>();
    public void StakeClaim(Plot plot)
    {
        if (!IsClaimStaked(plot))
        {
            claims.Add(plot);
        }
    }

    public bool IsClaimStaked(Plot plot) => claims.Contains(plot);

    public bool IsLastClaim(Plot plot) => plot.Equals(claims.Last());

    public Plot GetClaimWithLongestSide() => claims.OrderByDescending(p => p.longest).First();
}
