public class CircularBuffer<T>
{
    private readonly int _cap;
    private List<T> _buff;


    public CircularBuffer(int capacity)
    {
        _cap = capacity;
        _buff = new List<T>(capacity);
    }

    public T Read()
    {
        if (_buff.Count == 0)
        {
            throw new InvalidOperationException("Buffer is empty.");
        }

        var ret = _buff[0];
        newHead();
        return ret;
    }

    public void Write(T value)
    {
        if (_buff.Count == _cap)
        {
            throw new InvalidOperationException("Buffer is full.");
        }

        _buff.Add(value);
    }

    public void Overwrite(T value)
    {

        if (_buff.Count == _cap)
        {
            newHead();
        }
        Write(value);
    }

    public void Clear()
    {
        _buff.Clear();
    }

    //shifts the head (or start) of the the array one ot the 'right' and drops the previous value
    private void newHead()
    {
        _buff = _buff.Skip(1).ToList();
    }
}
