int SumOfDigits(int x)
{
if (x == 0)
return 0;
return (x % 10 + SumOfDigits(n / 10));
}
