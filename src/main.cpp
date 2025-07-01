#include <borealis.hpp>
#include <cstdlib>
#include <string>

#include "activity/main_activity.hpp"
#include "tabs/install_tab.hpp"

using namespace brls::literals; // for _i18n

int main(int argc, char* argv[]) {
    // We recommend to use INFO for real apps
    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "-d") == 0) { // Set log level
            brls::Logger::setLogLevel(brls::LogLevel::LOG_DEBUG);
        } else if (std::strcmp(argv[i], "-o") == 0) {
            const char* path = (i + 1 < argc) ? argv[++i] : "borealis.log";
            brls::Logger::setLogOutput(std::fopen(path, "w+"));
        } else if (std::strcmp(argv[i], "-v") == 0) {
            brls::Application::enableDebuggingView(true);
        }
    }

    // Init the app and i18n
    if (!brls::Application::init()) {
        brls::Logger::error("Unable to init Borealis application");
        return EXIT_FAILURE;
    }

    brls::Application::createWindow("app/title"_i18n);

    brls::Application::getPlatform()->setThemeVariant(brls::ThemeVariant::DARK);

    // Have the application register an action on every activity that will quit
    // when you press BUTTON_START
    brls::Application::setGlobalQuit(false);

    // Register custom views (including tabs, which are views)
    brls::Application::registerXMLView("InstallTab", InstallTab::create);

    // Add custom values to the theme
    // brls::Theme::getLightTheme().addColor("captioned_image/caption",
    // nvgRGB(2, 176, 183));
    // brls::Theme::getDarkTheme().addColor("captioned_image/caption",
    // nvgRGB(51, 186, 227));

    // Add custom values to the style
    brls::getStyle().addMetric("about/padding_top_bottom", 50);
    brls::getStyle().addMetric("about/padding_sides", 75);
    brls::getStyle().addMetric("about/description_margin", 50);

    // Create and push the main activity to the stack
    brls::Application::pushActivity(new MainActivity());

    // Run the app
    while (brls::Application::mainLoop())
        ;

    // Exit
    return EXIT_SUCCESS;
}

#ifdef __WINRT__
#include <borealis/core/main.hpp>
#endif
