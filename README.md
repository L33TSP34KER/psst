# 1. psst
cross shell prompt in c++ easily hackable to do exactly what you want

I always liked the philosphy of st (suckless) terminal.

# 2. Customisation
With this tool i tried to implement suckless mentality.
To edit the prompt just open src/commands/init.cpp to put any prompt you want.
### examples
![example1](imgs/ex1.png)

![example2](imgs/ex2.png)

![example3](imgs/ex3.png)

### my own config
![mine](imgs/mine.png)

```cpp
 return {
        std::make_unique<Purple>(),
        std::make_unique<Separator>("\n "),
        std::make_unique<Reset>(),
        std::make_unique<Cyan>(),
        std::make_unique<User>(),
        std::make_unique<Reset>(),

        std::make_unique<Separator>(" "),
        std::make_unique<Path>(),
        
        std::make_unique<Separator>(" "),
        std::make_unique<Red>(),
        std::make_unique<Git>(5),

        std::make_unique<Separator>(" "),
        std::make_unique<GitBranch>(),
        std::make_unique<Reset>(),

        std::make_unique<Separator>(" "),
        std::make_unique<Battery>(),
        std::make_unique<Purple>(),
        std::make_unique<Separator>("\n"),
        std::make_unique<Reset>(),
        
        std::make_unique<Purple>(),
        std::make_unique<Bold>(),
        std::make_unique<Separator>(" "),
        std::make_unique<Reset>(),
        std::make_unique<Separator>(" ")
    };

```

# 3. Contributing
You can get the list of widgets in src/widgets/ If you want to add compatibility for a shell you can add it in src/shells/
