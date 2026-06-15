# BeepBoopLang

**BeepBoopLang** replaces common C++ keywords with BeepBoop terminology. Programs written in BeepBoop are transpiled into standard C++ before compilation. Most of the syntax still follows C++ standards.


## Keywords

| Keyword        | Meaning                    | Example                                    |
| -------------- | -------------------------- | ------------------------------------------ |
| `BeepBoop`     | Print                      | `BeepBoop "Hello World";`                  |
| `Boop`         | Declare Variable           | `Boop BupBeep = 2.0;`                      |
| `BoopBop`      | Declare Function           | `BoopBop BupBeep(...){...}`                |
| `Beep`         | If Statement               | `Beep (...){...}`                          |
| `Bop`          | Else Statement             | `Bop {...}`                                |
| `BopBeep`      | Else If Statement          | `BopBeep (...){...}`                       |
| `BoopBoop`     | While Loop                 | `BoopBoop (...){...}`                      |
| `BopBop`       | For Loop                   | `BopBop (...){...}`                        |
| `BopBoop`      | Break                      | `BopBoop;`                                 |
| `BeepBeep`     | Return                     | `BeepBeep "Sad trumpet";`                  |
| `Bap`          | Add to Array               | `BupBeep Bap("This is added to the top");` |
| `Bip`          | Get Array Size             | `BupBeep Bip;`                             |
| `Bup`          | Erase Array Index          | `BupBeep Bup(3);`                          |
| `BeepBeepBeep` | Function Section Delimiter | `BeepBeepBeep ... BeepBeepBeep`            |


## Rules

### 1. Use `.BeepBoop` Files

BeepBoopLang source files **must** use the `.BeepBoop` extension. The transpiler will reject any other file type.

```text
Sample.BeepBoop
```

*Just being fancy ₍๑ᵔ⤙ᵔ๑)*


### 2. Functions Must Be Inside the Function Section

All functions must be declared between `BeepBeepBeep` markers.

Even if your program does not contain functions, the function section must still exist.

```cpp
BeepBeepBeep

BoopBop BupBeepBop(Boop BupBop, Boop BupBopBop)
{
    Boop BupBeepBep = 0;

    BupBeepBep = BupBop + BupBopBop;

    BeepBeep BupBeepBep;
}

BeepBeepBeep
```

### 3. Variables Must Be Initialized

```cpp
Boop BupBeep;      // Incorrrect
Boop BupBeep = 10; // Correct
```

## Sample Program

```cpp
////////////////////////////////
// BeepBoop Program File
// Demo: Full keyword usage
////////////////////////////////

BeepBeepBeep

BoopBop BupBeepBop(Boop BupBop, Boop BupBopBop)
{
    Boop BupBeepBep = 0;

    BupBeepBep = BupBop + BupBopBop;

    BeepBeep BupBeepBep;
}

BeepBeepBeep

Boop BupBop = 0;
Boop BupBoopBoop = {1,2,3,4,5};

// Simulated loop using For
BopBop (Boop BupBeep = 1; BupBeep < 5; BupBeep++)
{
    BeepBoop "For Loop iteration\n";

    // If / Else If / Else chain
    Beep (BupBeep == 1)
    {
        BeepBoop "BupBeep is 1\n";
    }
    Beep (BupBeep % 2 == 0)
    {
        BeepBoop "BupBeep is even\n";
    }
    BopBeep (BupBeep % 3 == 0)
    {
        BeepBoop "BupBeep divisible by 3\n";
    }
    Bop
    {
        BeepBoop "Hi World!\n";
    }

    BupBop = 0;

    // While example
    BoopBoop (BupBop < 10)
    {
        BeepBoop "while running\n";
        BupBop += 1;

        if (BupBop == 2)
        {
            BopBoop;
        }
    }

    BeepBoop "Array size: ";
    BeepBoop BupBoopBoop Bip;
    BeepBoop "\n";

    BeepBoop "Add to array: ";
    BupBoopBoop Bap(5);
    BeepBoop BupBoopBoop Bip;
    BeepBoop "\n";

    BeepBoop "Erase from array: ";
    BupBoopBoop Bup(2);
    BeepBoop BupBoopBoop Bip;
    BeepBoop "\n";
}

BeepBoop "Modify array value: ";
BupBoopBoop[0] = 100;
BeepBoop BupBoopBoop[0];
```


## How to Use

### Using the Portable Release

1. Extract `BeepBoopLang.zip` anywhere on your computer.
2. Open a terminal in the extracted folder.
3. Run the following command:

```powershell
.\BeepBoopLang.exe run Sample.BeepBoop
```

4. It should work (It should... (ó﹏ò｡) )


### Building from Source

Alternatively, you can compile the source code from GitHub and use your own C++ compiler.


## External Links

* [GitHub Repository](https://github.com/Sarkozy8/BeepBoopLang)
* [Portable Download](https://drive.google.com/file/d/1UEaUCxCunC9mpXxP1OaBC1_UrgKRoDXQ/view?usp=sharing)

# Congratulations! You are now fluent in BeepBoop.
