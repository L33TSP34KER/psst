#include <vector>
#include "widgets/Battery.hpp"
#include "widgets/Git.hpp"
#include "widgets/GitBranch.hpp"
#include "widgets/IWidget.hpp"
#include "widgets/Path.hpp"
#include "widgets/Separator.hpp"
#include "widgets/User.hpp"
#include "widgets/colors/Cyan.hpp"
#include "widgets/colors/Bold.hpp"
#include "widgets/colors/Red.hpp"
#include "widgets/colors/Purple.hpp"
#include "widgets/colors/Reset.hpp"
#include "shells/EShell.hpp"
#include "shells/IShell.hpp"

std::vector<std::shared_ptr<IWidget>> default_config() {
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
        std::make_unique<Separator>(" "),
        std::make_unique<Separator>("\n", 0),
        std::make_unique<Reset>(),
        
        std::make_unique<Purple>(),
        std::make_unique<Bold>(),
        std::make_unique<Separator>(" ", 0),
        std::make_unique<Reset>(),
        std::make_unique<Separator>(" ")
    };
}


