using System.Collections.Generic;
using System.Collections.ObjectModel;

public class Authenticator
{
    private class EyeColor
    {
        const string Blue = "blue";
        const string Green = "green";
        const string Brown = "brown";
        const string Hazel = "hazel";
        const string Grey = "grey";
    }

    public Authenticator(Identity admin) => this.admin = admin;

    private Identity admin;

    private IDictionary<string, Identity> developers
        = new Dictionary<string, Identity>
        {
            ["Bertrand"] = new Identity
            {
                Email = "bert@ex.ism",
                EyeColor = "blue"
            },

            ["Anders"] = new Identity
            {
                Email = "anders@ex.ism",
                EyeColor = "brown"
            }
        };

    public Identity Admin
    {
        get { return admin; }
        set { admin = value; }
    }

    public IDictionary<string, Identity> GetDevelopers() => new ReadOnlyDictionary<string, Identity>(developers);
}

public struct Identity
{
    public string Email { get; set; }

    public string EyeColor { get; set; }
}
