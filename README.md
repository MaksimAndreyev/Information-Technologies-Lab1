# Структура:
## Папка Tester:
**Tester.c** - глобальный тестировщик, вызывающий модули *RobotTester* и *GameSysTester*
### Папка testRobotIO:
**RobotTester.c** - тестировщик целого модуля *RobotIO*, вызывает функции из *RobotIOTesterModules*  
**RobotIOTesterModules.c** - набор функций, тестирующих отдельные функции модуля *RoboIO*  
### Папка testGameSystem:
**GameSysTester.c** - тестировщик целого модуля *GameSystem*, вызывает функции из *GameSysTesterModules*  
**GameSysTesterModules.c** - набор функций, тестирующих отдельные функции модуля *GameSystem* 
## Папка RobotIO:
**RobotIO.c** - модуль ИИ, содержит функции: *GetRobotShipKoords* и *GetRobotTarget*
## Папка GameSystem:
**GameSystem.c** - модуль, отвечающий за внутреннюю логику игры, содержит функции: *Shoot* и *PlaceShip*\
# Символы и их значение на поле:
\# - Пустая не стрелянная клетка\
0 - Пустая стрелянная клетка\
\* - Уничтоженная палуба\
@ - Целая палуба