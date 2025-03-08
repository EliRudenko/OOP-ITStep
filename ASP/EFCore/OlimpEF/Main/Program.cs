using Main;
using Microsoft.EntityFrameworkCore;
using Models;
using OlympiadEFCore;

start:
int choice;
do
{
    Printers.PrintMain();
    choice = int.Parse(Console.ReadLine());
} while(choice <= 0 || choice > 4);

switch (choice)
{
    case 1:
        do
        {
            Printers.PrintActions();
            choice = int.Parse(Console.ReadLine());
        } while (choice <= 0 || choice > 5);

        switch (choice)
        {
            case 1:
                Console.Clear();
                Console.WriteLine("Name:");
                string name = Console.ReadLine();

                Console.WriteLine("Surname:");
                string surname = Console.ReadLine();

                Console.WriteLine("Birthday (yyyy-MM-dd):");
                DateOnly birthday;
                while (!DateOnly.TryParse(Console.ReadLine(), out birthday))
                {
                    Console.WriteLine("Invalid date format. Try again (yyyy-MM-dd):");
                }

                using (var db = new OlympiadContext())
                {
                    Country? countryQuery;
                    do
                    {
                        Console.Write("Country: ");
                        string country = Console.ReadLine().Trim();
                        countryQuery = db.Countries.FirstOrDefault(c => c.Name == country);
                        if (countryQuery == null)
                            Console.WriteLine("Country not found. Try again.");
                    } while (countryQuery == null);

                    City? cityQuery;
                    do
                    {
                        Console.Write("City: ");
                        string cityStr = Console.ReadLine().Trim();
                        cityQuery = db.Cities.FirstOrDefault(c => c.Name == cityStr);
                        if (cityQuery == null)
                            Console.WriteLine("City not found. Try again.");
                    } while (cityQuery == null);

                    Sport? sport;
                    do
                    {
                        Console.Write("Sport: ");
                        string sportStr = Console.ReadLine().Trim();
                        sport = db.Sports.FirstOrDefault(s => s.Name == sportStr);

                        if (sport == null)
                            Console.WriteLine("Sport not found. Try again.");
                    } while (sport == null);

                    Olympiad? olympiad;
                    do
                    {
                        Console.Write("Olympiad year: ");
                        int year = int.Parse(Console.ReadLine());
                        olympiad = db.Olympiads.FirstOrDefault(o => o.Year == year);
                        if (olympiad == null)
                            Console.WriteLine("Try again.");
                    } while (olympiad == null);
                    var participant = new Participant { Name = name,Surname = surname,Birthday = birthday,City = cityQuery,Sport = sport, Olympiad = olympiad};
                    var isExist = db.Participants.FirstOrDefault(p => p == participant);
                    if (isExist == null)
                        db.Participants.Add(participant);
                    else
                    {
                        Console.WriteLine("Participant already exists");
                        goto start;
                    }
                    try
                    {
                        db.SaveChanges();
                        Console.WriteLine("Participant has been added!");
                        Thread.Sleep(3000);
                        goto start;
                    }catch(DbUpdateException ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }


                break;
            case 2:
                Console.Clear();
                Console.Write("Participant Id: ");
                if (!int.TryParse(Console.ReadLine(), out int updatePartId))
                {
                    Console.WriteLine("Invalid ID format. Returning to menu...");
                    Thread.Sleep(2000);
                    goto start;
                }

                using (var db = new OlympiadContext())
                {
                    var participant = db.Participants
                        .Include(p => p.City)
                        .Include(p => p.City.Country)
                        .Include(p => p.Sport)
                        .Include(p => p.Olympiad)
                        .FirstOrDefault(p => p.Id == updatePartId);

                    if (participant == null)
                    {
                        Console.WriteLine("Participant not found.");
                        Thread.Sleep(2000);
                        goto start;
                    }

                    Console.Clear();
                    Console.WriteLine("Updating Participant Details:");
                    Console.WriteLine($"Current Name: {participant.Name}");
                    Console.Write("New Name (press Enter to keep current): ");
                    string newName = Console.ReadLine().Trim();
                    if (!string.IsNullOrEmpty(newName))
                        participant.Name = newName;

                    Console.WriteLine($"Current Surname: {participant.Surname}");
                    Console.Write("New Surname (press Enter to keep current): ");
                    string newSurname = Console.ReadLine().Trim();
                    if (!string.IsNullOrEmpty(newSurname)) 
                        participant.Surname = newSurname;

                    Console.WriteLine($"Current Birthday: {participant.Birthday}");
                    Console.Write("New Birthday (yyyy-MM-dd, press Enter to keep current): ");
                    string birthdayInput = Console.ReadLine().Trim();
                    if (!string.IsNullOrEmpty(birthdayInput) && DateOnly.TryParse(birthdayInput, out DateOnly newBirthday))
                    {
                        participant.Birthday = newBirthday;
                    }

                    Country? newCountry = null;
                    do
                    {
                        Console.WriteLine($"Current Country: {participant.City?.Country?.Name}");
                        Console.Write("New Country (press Enter to keep current): ");
                        string countryInput = Console.ReadLine().Trim();
                        if (string.IsNullOrEmpty(countryInput)) 
                            break;

                        newCountry = db.Countries.FirstOrDefault(c => c.Name == countryInput);
                        if (newCountry == null)
                            Console.WriteLine("Country not found. Try again.");
                    } while (newCountry == null);

                    City? newCity = null;
                    do
                    {
                        Console.WriteLine($"Current City: {participant.City?.Name}");
                        Console.Write("New City (press Enter to keep current): ");
                        string cityInput = Console.ReadLine().Trim();
                        if (string.IsNullOrEmpty(cityInput)) break;

                        newCity = db.Cities.FirstOrDefault(c => c.Name == cityInput);
                        if (newCity == null)
                            Console.WriteLine("City not found. Try again.");
                    } while (newCity == null);

                    Sport? newSport = null;
                    do
                    {
                        Console.WriteLine($"Current Sport: {participant.Sport?.Name}");
                        Console.Write("New Sport (press Enter to keep current): ");
                        string sportInput = Console.ReadLine().Trim();
                        if (string.IsNullOrEmpty(sportInput)) 
                            break;

                        newSport = db.Sports.FirstOrDefault(s => s.Name == sportInput);
                        if (newSport == null)
                            Console.WriteLine("Sport not found. Try again.");
                    } while (newSport == null);

                    Olympiad? newOlympiad = null;
                    do
                    {
                        Console.WriteLine($"Current Olympiad Year: {participant.Olympiad?.Year}");
                        Console.Write("New Olympiad Year (press Enter to keep current): ");
                        string olympiadInput = Console.ReadLine().Trim();
                        if (string.IsNullOrEmpty(olympiadInput)) 
                            break;

                        if (int.TryParse(olympiadInput, out int newOlympiadYear))
                        {
                            newOlympiad = db.Olympiads.FirstOrDefault(o => o.Year == newOlympiadYear);
                            if (newOlympiad == null)
                                Console.WriteLine("Olympiad not found. Try again.");
                        }
                        else
                        {
                            Console.WriteLine("Invalid year format. Try again.");
                        }
                    } while (newOlympiad == null);

                    if (newCity != null) 
                        participant.City = newCity;
                    if (newSport != null) 
                        participant.Sport = newSport;
                    if (newOlympiad != null) 
                        participant.Olympiad = newOlympiad;

                    try
                    {
                        db.SaveChanges();
                        Console.WriteLine("Participant updated successfully!");
                    }
                    catch (DbUpdateException ex)
                    {
                        Console.WriteLine($"Error updating participant: {ex.Message}");
                    }

                    Thread.Sleep(3000);
                    goto start;
                }

            case 3:
                Console.Clear();
                Console.Write("Participant Id: ");
                int removePartId = int.Parse(Console.ReadLine());
                using(var db = new OlympiadContext())
                {
                    var query = db.Participants.FirstOrDefault(p=> p.Id == removePartId);
                    if(query == null)
                    {
                        Console.WriteLine("No such participant");
                        goto start;
                    }

                    db.Participants.Remove(query);
                    try
                    {
                        db.SaveChanges();
                    }
                    catch (DbUpdateException ex)
                    {
                        Console.WriteLine($"{ex.Message}");
                    }

                    Console.WriteLine($"Participant {removePartId} has been deleted");
                }
                break;
            case 4:
                Console.Clear();
                using (var db = new OlympiadContext())
                {
                    var participants = db.Participants
                        .Include(p => p.City)     
                        .ThenInclude(c => c.Country) 
                        .Include(p => p.Sport)     
                        .Include(p => p.Olympiad) 
                        .ToList(); 
                    foreach (var participant in participants)
                    {
                        Console.WriteLine($"#{participant.Id}.\n" +
                            $"Name: {participant.Name}\n" + 
                            $"Surname: {participant.Surname}\n" + 
                            $"Birthday: {participant.Birthday.ToString()}\n" + 
                            $"Country: {participant.City.Country.Name}\n" +
                            $"City: {participant.City.Name}\n" + 
                            $"Sport: {participant.Sport.Name}\n" + 
                            $"Olympiad year: {participant.Olympiad.Year}\n"); 
                    }
                }

                break;
            case 5:
                goto start;
        }

        break;
    case 2:
        do
        {
            Printers.PrintActions();
            choice = int.Parse(Console.ReadLine());
        } while (choice <= 0 || choice > 5);
        switch (choice)
        {
            case 1:
                Console.Write("Name of a new sport:");
                string newSportStr = Console.ReadLine().Trim();
                using(var db = new OlympiadContext())
                {
                    var query = db.Sports.FirstOrDefault(s=>s.Name == newSportStr);
                    if(query != null)
                    {
                        Console.WriteLine("This sport category already exists");
                        Thread.Sleep(3000);
                        goto start;
                    }
                    var newSport = new Sport { Name = newSportStr };
                    db.Sports.Add(newSport);
                    try
                    {
                        db.SaveChanges();
                    }catch(DbUpdateException ex)
                    {
                        Console.WriteLine($"{ex.Message}");
                    }

                    Console.WriteLine("New sport has been added");
                    Thread.Sleep(3000);
                    goto start;
                }
            case 2:
                Console.Clear();
                Console.Write("Choose old sport:");
                string oldSport = Console.ReadLine().Trim();
                using(var db = new OlympiadContext())
                {
                    var updateSport = db.Sports.FirstOrDefault(s=>s.Name == oldSport);
                    if(updateSport == null)
                    {
                        Console.WriteLine("This sport doesn`t exist");
                        goto start;
                    }
                    db.Sports.Attach(updateSport);
                    Console.Write("Choose new name for this sport:");
                    string newSport = Console.ReadLine().Trim();
                    if(newSport == null)
                    {
                        Console.WriteLine("Incorrect format");
                        Thread.Sleep(3000);
                        goto start;
                    }
                    updateSport.Name = newSport;
                    try
                    {
                        db.SaveChanges();
                    }catch(DbUpdateException ex)
                    {
                        Console.WriteLine($"{ex.Message}");
                    }

                    Console.WriteLine("Sport name has been updated");
                    Thread.Sleep(3000);
                    goto start;
                }
            case 3:
                Console.Clear();
                Console.Write("Name:");
                string deleteSportStr = Console.ReadLine().Trim();
                using (var db = new OlympiadContext()) 
                {
                    var query = db.Sports.FirstOrDefault(s => s.Name == deleteSportStr);
                    if(query == null)
                    {
                        Console.WriteLine("This sport doesn`t exist");
                        Thread.Sleep(3000);
                        goto start;
                    }

                    db.Sports.Remove(query);
                    Console.WriteLine("Sport has been removed");
                    Thread.Sleep(3000);
                    goto start;
                }
            case 4:
                Console.Clear();
                using(var db =  new OlympiadContext())
                {
                    var sportList = db.Sports.ToList();
                    foreach(var sport in sportList)
                    {
                        Console.WriteLine(sport.Name);
                    }
                }
                break;
            case 5:
                goto start;
        }
        break;
    case 3:
        do
        {
            Printers.PrintActions();
            choice = int.Parse(Console.ReadLine());
        } while (choice <= 0 || choice > 5);
        switch (choice) {
            case 1:
                Console.Clear();
                Console.Write("Participant ID:");
                int partId;
                int.TryParse(Console.ReadLine(), out partId);

                using (var db = new OlympiadContext())
                {
                    var participant = db.Participants
                        .Include(p => p.Olympiad)
                        .FirstOrDefault(p => p.Id == partId);

                    if (participant == null)
                    {
                        Console.WriteLine("No such participant");
                        Thread.Sleep(3000);
                        goto start;
                    }
                    int place;
                    do
                    {
                        Console.Write("Place:");
                        place = int.Parse(Console.ReadLine());
                    } while (place < 1 || place > 64);

                    Result result = new Result { Participant = participant, Olympiad = participant.Olympiad, Place = place };
                    db.Results.Add(result);
                    try
                    {
                        db.SaveChanges();
                    } catch (DbUpdateException ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                    Console.WriteLine("Result has been added");
                }
                break;
            case 2:
                Console.Clear();
                Console.Write("Choose old result id:");
                int oldResult;
                int.TryParse(Console.ReadLine(), out oldResult);
                using (var db = new OlympiadContext())
                {
                    var updatedResult = db.Results
                        .FirstOrDefault(r => r.Id == oldResult);
                    if (updatedResult == null)
                    {
                        Console.WriteLine("This result doesn`t exist");
                        goto start;
                    }
                    db.Results.Attach(updatedResult);
                    Console.Write("Choose new place for this result:");
                    int newResult;
                    int.TryParse(Console.ReadLine(), out newResult);

                    if (newResult < 1 || newResult >64)
                    {
                        Console.WriteLine("Incorrect format");
                        Thread.Sleep(3000);
                        goto start;
                    }
                    updatedResult.Place = newResult;
                    try
                    {
                        db.SaveChanges();
                    }
                    catch (DbUpdateException ex)
                    {
                        Console.WriteLine($"{ex.Message}");
                    }

                    Console.WriteLine("Result place has been updated");
                    Thread.Sleep(3000);
                    goto start;
                }
            case 3:
                Console.Clear();
                Console.Write("Choose result id:");
                int deletedId;
                int.TryParse(Console.ReadLine(), out deletedId);
                using(var db = new OlympiadContext())
                {
                    var deletedResult = db.Results.FirstOrDefault(r=>r.Id == deletedId);
                    if(deletedResult == null)
                    {
                        Console.WriteLine("There is no result with this ID");
                        Thread.Sleep(3000);
                        goto start;
                    }
                    db.Results.Remove(deletedResult);
                    try
                    {
                        db.SaveChanges();
                    }
                    catch (DbUpdateException ex) {
                        Console.WriteLine($"{ex.Message}");
                    }
                    Console.WriteLine("Result has been deleted");
                    Thread.Sleep(3000);
                    goto start;
                }


            case 4:
                using (var db = new OlympiadContext())
                {
                    var results = db.Results
                        .Include(r => r.Participant)
                        .ThenInclude(p => p.Sport)
                        .Include(r => r.Olympiad);
                    foreach(var result in results)
                    {
                        Console.WriteLine($"#{result.Id}\n" +
                            $"Name:{result.Participant.Name} {result.Participant.Surname}\n" +
                            $"Place:{result.Place}\n" +
                            $"Sport:{result.Participant.Sport.Name}\n" +
                            $"Olympiad year:{result.Olympiad.Year}\n");
                        Console.WriteLine();
                        Console.WriteLine();
                    }
                    break;
                }
            case 5:
                goto start;
        }
        break;
    case 4:
        using (var db = new OlympiadContext())
        {
            Console.Clear();
            var olympiads = db.Olympiads.ToList();
            foreach(var item in olympiads)
            {
                Console.WriteLine($"#{item.Id}\n" +
                    $"Year:{item.Year}");
                Console.WriteLine();
            }
            break;
        }
        break;


}


