```
 ____          _   _ _  __    _____ _____ __  __ _    _ _            _______ _____ ____  _   _ 
 |  _ \   /\   | \ | | |/ /   / ____|_   _|  \/  | |  | | |        /\|__   __|_   _/ __ \| \ | |
 | |_) | /  \  |  \| | ' /   | (___   | | | \  / | |  | | |       /  \  | |    | || |  | |  \| |
 |  _ < / /\ \ | . ` |  <     \___ \  | | | |\/| | |  | | |      / /\ \ | |    | || |  | | . ` |
 | |_) / ____ \| |\  | . \    ____) |_| |_| |  | | |__| | |____ / ____ \| |   _| || |__| | |\  |
 |____/_/    \_\_| \_|_|\_\  |_____/|_____|_|  |_|\____/|______/_/    \_\_|  |_____\____/|_| \_|
```

Realised by Aldric VITALI SILVESTRE and Nicolas CIBULKA
 
# Table of contents
 
- [How to install](#How-to-install)
- [Basic usage](#Basic-usage)
    - [Interactive usage](#Interactive-usage)
    - [CLI-based usage](#CLI-based-usage)
- [Work repartition](#Work-repartition)

# How to install

In the root folder, you can use the "make" command to build various targets : 
 - doc : this generate a folder named "doc" containing the entire documentation on html and LaTeX format. A symbolic link of the index.html file is also created in the doc folder in order to access the home page of the documentation more easily.
 - bank_simulation : the main executable of the project to use.
 - textBank : a simple executable to launch a simulation with hard-coded values.
 - testInput : another simple executable. This will ask the user for inputs or try to retrieve from CLI arguments, but it will not launch a simulation.

In most cases, you just want to generate documentation and create the main executable. You can therefore run the command `$ make default` in order to generate only those two targets.

However, the command `$ make all` will generate all targets.

All object files will be created in the `build` folder, and the executables in the `bin` folder.

# Basic usage

You can launch the application in two different ways :

## Interactive usage

If the application is called without any additionnal parameters, you will face multiple prompts in order to provide all required inputs for the simulation. The prompt looks like this :
```shell
Expected duration : 200
Number of cashiers : 3
Put the average processing times of each cashier (separated by a space) :
1 2 3
Average arrival time : 12
```

If any wrong value is provided, an error will be displayed and you will have to give a different value. This behavior is infinite, until all values given are valid.

## CLI-based usage

If any additionnal parameter is provided when calling the executable, the application will try to parse all needed arguments, and display an error message if any error occurs (wrong value, undefined parameter, etc.). If no errors occurs, the simulation will run directly.

Here is the list of arguments to put :
- "-d" : the expected duration of the simulation (double, positive number).
- "-c" : the number of cashiers in the bank (integer, positive number).
- "-t" : the list of average service time for each cashier. This is a list of doubles separated by a space. The list size must be the same as the cashier count (parameter "-c").
- "-a" : the average client arrival time (double, positive number).

An example of command to run :
```shell
./bin/bank_simulation -d 200 -c 3 -a 5 -t 23.1 12.1 7.2
```
This command will call the main executable with following inputs :
- An expected duration of 200.0
- 3 cashiers in the bank, with average service times respectively of 23.1, 12.1 and 7.2
- An average client arrival of 5.0

# Work repartition

The work has been distributed like this :

| Part of the project                          | Nicolas             | Aldric               |
|----------------------------------------------|---------------------|----------------------|
| Creation and intialisation of the repository |                     | :heavy_check_mark:   |
| Creation of .h files                         | :heavy_check_mark:  | :heavy_check_mark:   | 
| Event and Arrival/Departure                  | :heavy_check_mark:  |                      | 
| SED                                          | :heavy_check_mark:  |                      | 
| Bank and waitingLine                         |                     | :heavy_check_mark:   | 
| README                                       | :heavy_check_mark:  | :heavy_check_mark:   | 
| User Interface                               |                     | :heavy_check_mark:   | 
