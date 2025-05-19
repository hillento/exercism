pub fn squareOfSum(number: usize) usize {
    const n = number;
    var sum: usize = 0;
    for (0..n + 1) |i| {
        sum = sum + i;
    }
    return sum * sum;
}

pub fn sumOfSquares(number: usize) usize {
    const n = number;
    var sum: usize = 0;
    for (0..n + 1) |i| {
        sum = sum + (i * i);
    }
    return sum;
}

pub fn differenceOfSquares(number: usize) usize {
    return squareOfSum(number) - sumOfSquares(number);
}
