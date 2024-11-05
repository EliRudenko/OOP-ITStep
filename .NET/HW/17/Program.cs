using System;

public class CreditCard
{
    public string CardNumber { get; private set; }
    public string OwnerName { get; private set; }
    public DateTime ExpiryDate { get; private set; }
    private string PinCode;
    public decimal CreditLimit { get; private set; }
    public decimal Balance { get; private set; }



    public event Action<decimal> TargetBalanceReached;
    public event Action CreditLimitUsed;




    public CreditCard(string cardNumber, string ownerName, DateTime expiryDate, string pinCode, decimal creditLimit, decimal initialBalance)
    {
        CardNumber = cardNumber;
        OwnerName = ownerName;
        ExpiryDate = expiryDate;
        PinCode = pinCode;
        CreditLimit = creditLimit;
        Balance = initialBalance;
    }

    public void Deposit(decimal amount)
    {
        if (amount <= 0)
        {
            Console.WriteLine("Сумма пополнения должна быть больше нуля.");
            return;
        }
        Balance += amount;
        Console.WriteLine($"Счет пополнен на сумму: {amount}. Текущий баланс: {Balance}");


        TargetBalanceReached?.Invoke(Balance);
    }

    public void Withdraw(decimal amount)
    {
        if (amount <= 0)
        {
            Console.WriteLine("Сумма снятия должна быть больше нуля.");
            return;
        }

        if (Balance - amount < -CreditLimit)
        {
            Console.WriteLine("Превышен кредитный лимит!");
            return;
        }

        Balance -= amount;
        Console.WriteLine($"Снятие со счета: {amount}. Текущий баланс: {Balance}");

        if (Balance < 0)
        {
            CreditLimitUsed?.Invoke();
        }
    }

    public void ChangePinCode(string oldPin, string newPin)
    {
        if (oldPin == PinCode)
        {
            PinCode = newPin;
            Console.WriteLine("ПИН-код успешно изменен.");
        }
        else
        {
            Console.WriteLine("Неверный старый ПИН-код.");
        }
    }

    public void SetTargetBalance(decimal targetAmount)
    {
        TargetBalanceReached += (currentBalance) =>
        {
            if (currentBalance >= targetAmount)
            {
                Console.WriteLine($"Достигнута заданная сумма: {targetAmount}");
            }
        };
    }
}




class Program
{
    static void Main()
    {
        CreditCard myCard = new CreditCard("9284 5618 9092 3486", "Иван Иванов", new DateTime(2025, 12, 31), "1234", 5000, 1000);

        myCard.CreditLimitUsed += () => Console.WriteLine("Начато использование кредитных средств.");
        myCard.SetTargetBalance(2000);

        myCard.Deposit(500);
        myCard.Withdraw(3000);
        myCard.ChangePinCode("1234", "4321");
    }
}
