# UE4 Tests Helpers

A simple developer plugins to gives some extras tools for **[specs](https://docs.unrealengine.com/en-US/Programming/Automation/AutomationSpec/index.html)** and **[unit tests](https://docs.unrealengine.com/en-US/Programming/Automation/TechnicalGuide/index.html)**.

<!-- TOC -->

-   [1. Assertions Macros](#1-assertions-macros)
-   [2. World Helpers](#2-world-helpers)
-   [3. Contributing and Supporting](#3-contributing-and-supporting)

<!-- /TOC -->

|                                                                                                       <a href="https://www.buymeacoffee.com/NansUE4" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-green.png" alt="Buy Me A Coffee" height="51" width="217"></a>                                                                                                       |
| :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| I've decided to make all the code I developed for my games free to use and open source.<br> I am a true believer in the mindset that sharing and collaborating makes the world a better place.<br> The thing is: I'm fulltime dedicated to my project and these open source plugins, for coding I need a looooot of coffee, so please, help me to get my drug :stuck_out_tongue_closed_eyes: !! |

<a id="markdown-1-assertions-macros" name="1-assertions-macros"></a>

## 1. Assertions Macros

Every assertions logs the `TextInformations` to the console and in the tests results.

| Assertion                                         | Verifies                                                          |
| :------------------------------------------------ | ----------------------------------------------------------------- |
| `TEST_EQ(TextInformations, expression, expected)` | `expression == expected`                                          |
| `TEST_NE(TextInformations, expression, expected)` | `expression != expected`                                          |
| `TEST_GT(TextInformations, expression, expected)` | `expression > expected`                                           |
| `TEST_GE(TextInformations, expression, expected)` | `expression >= expected`                                          |
| `TEST_LT(TextInformations, expression, expected)` | `expression < expected`                                           |
| `TEST_LE(TextInformations, expression, expected)` | `expression <= expected`                                          |
| `TEST_TRUE(TextInformations, expression)`         | `expression == true`                                              |
| `TEST_FALSE(TextInformations, expression)`        | `expression == false`                                             |
| `TEST_NOT_NULL(TextInformations, expression)`     | `expression != nullptr`                                           |
| `TEST_NULL(TextInformations, expression)`         | `expression == nullptr`                                           |
| `TEST_THROW(expression, expected)`                | `try {expression} catch(expected) { true } catch (...) { false }` |

<a id="markdown-2-world-helpers" name="2-world-helpers"></a>

## 2. World Helpers

[TestWorld.h](NansUE4TestsHelpers\Public\Helpers\TestWorld.h)

| Helper                                                                                | What it does                                                         |
| ------------------------------------------------------------------------------------- | -------------------------------------------------------------------- |
| `NTestWorld::CreateAndPlay(EWorldType::Type)`                                         | Create a default world and play it                                   |
| `NTestWorld::CreateAndPlay(EWorldType::Type, true)`                                   | + add a UFakeGameInstance as Game instance                           |
| `NTestWorld::CreateAndPlay(EWorldType::Type, true, FName("myName"))`                  | + with a specific name (level name)                                  |
| `NTestWorld::CreateAndPlay(EWorldType::Type, true, FName("myName"), UClass* GIClass)` | + add GIClass (subclass of UFakeGameInstance) as Game instance class |
| `NTestWorld::Destroy(UWorld* World)`                                                  | Destroy a world                                                      |
| `NTestWorld::Tick(UWorld* World, float Time = 1.f)`                                   | Tick a world at the Time passed with 0.1secs steps                   |
| `NTestWorld::CreateAndOpenNewLevel(UWorld* World)`                                    | Allows to quit actual level and change with a default new one.       |

<a id="markdown-3-contributing-and-supporting" name="3-contributing-and-supporting"></a>

## 3. Contributing and Supporting

I've decided to make all the code I developed for my games free to use and open source.  
I am a true believer in the mindset that sharing and collaborating makes the world a better place.  
I'll be very glad if you decided to help me to follow my dream.

| How?                                                                                                                                                                               |                                                                                         With                                                                                         |
| :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| **Donating**<br> Because I'm an independant developer/creator and for now I don't have<br> any income, I need money to support my daily needs (coffeeeeee).                        | <a href="https://www.buymeacoffee.com/NansUE4" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-green.png" alt="Buy Me A Coffee" height="51" width="217" ></a> |
| **Contributing**<br> You are very welcome if you want to contribute. I explain [here](./CONTRIBUTING.md) in details what<br> is the most comfortable way to me you can contribute. |                                                                         [CONTRIBUTING.md](./CONTRIBUTING.md)                                                                         |
