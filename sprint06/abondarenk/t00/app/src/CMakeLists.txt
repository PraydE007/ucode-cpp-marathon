cmake_minimum_required(VERSION 3.18.2)

set(WIZARD_SRCS
    "Wizard/MightyWizard.cpp"
)

set(FOOD_SRCS
    "Food/ApplePie.cpp"
    "Food/FoodItem.cpp"
    "Food/HoneyNut.cpp"
    "Food/PoisonedFood.cpp"
    "Food/SweetRoll.cpp"
)

set(CPPS
    ${WIZARD_SRCS}
    ${FOOD_SRCS}
)

include_directories(".")
project("libMightyWizard" VERSION 0.1 LANGUAGES CXX)
add_library("libMightyWizard" ${CPPS})
target_include_directories("libMightyWizard" PUBLIC ${PROJECT_BINARY_DIR})
