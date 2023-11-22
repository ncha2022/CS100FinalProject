# Text Based RPG (Role Playing Game)
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: [Anish Kancherla](https://github.com/anishkancherla),  [Nolan Cha](https://github.com/ncha2022), [Josh Wang](https://github.com/jwang705), [Jenny Zhang](https://github.com/j3nnyz)

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include:
 > * Why is it important or interesting to you? 
>     -   Our project is interesting to us because we are all gamers so we are invested in making a good game.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
>     -   Languages: C++
>     -   Tool: VS code
 > * What will be the input/output of your project?
>     -  Keyboard inputs
>     -  Mouse inputs
 > * What are the features that the project provides?
 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted.
>     - Ascii graphics
>     - Engaging story
>     - Gambling system
>     - Turn based fighting
>     - Store system
>     - Character class system 
>     - Inventory system
 > 
 > You also need to set up an empty project board using GitHub projects (board view). Make sure you add the board under your project repository. You should also have a Product Backlog and In testing columns added.
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` (aka Sprint Backlog) column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.


 > * Schedule two check-ins using Calendly. You need to pick both time slots on Tuesday of week 6. The check-ins will occur on Zoom. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> ![image](https://github.com/cs100/final-project-ncha007-jzhan591-akanc003-jwang705/assets/102260019/edc2e688-79d1-45c7-95b9-74af3888b673)
> This navigation diagram shows how each screen is interlinked and how they transfer between themselves.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.
> ## Main Menu
> - **Commands:**
> - `New Game`: Starts a new game session.
> - `Load Game`: Loads a previously saved game session.
> - `Quit`: Exits the game.

> ## Character Creation
> - **Commands:**
> - `Choose Class`: Enter a command to select a class like Rogue, Knight, Mage, etc.
> - `Allocate Stats`: Assign stat points to attributes like Strength, Agility, Intelligence, etc.

> ## Class Selection
> - **Commands:**
> - `Select Class`: Choose your character's class from options such as [Rogue], [Knight], [Mage].

> ## Stats Allocation
> - **Commands:**
> - `Increase Stat`: Add points to a specific stat, ex, `Strength: 5 [+][-]`.
> - `Decrease Stat`: Subtract points from a specific stat.

> ## Gameplay
> - **Commands:**
> - `Inventory`: Opens the player's inventory to view items.
> - `Look Around`: Provides a description of the player's surroundings.
> - `Move`: Enter a direction to move your character, ex, `Move North`.
> - `Interact`: Engage with the environment or NPCs.

> ## Inventory System
> - **Commands:**
> - `Use Item`: Utilize an item from the inventory, ex, `Health Potion [Use]`.
> - `Equip Item`: Equip an item to the character, ex, `Sword [Equip]`.

> ## Store System
> - **Commands:**
> - `Buy Item`: Purchase an item from the store, ex, `Health Potion [Buy]`.

> ## Turn-Based Fighting
> - **Commands:**
> - `Attack`: Choose to attack the enemy.
> - `Defend`: Take a defensive stance to reduce damage.
> - `Use Item`: Use an item from your inventory during combat.
> - `Flee`: Attempt to escape from combat.

> ## Gambling System
> - **Commands:**
> - `Bet`: Place a bet in a game of chance, ex, `Dice Roll [Bet]`.

> ## Quit Confirmation
> - **Commands:**
> - `Confirm Quit`: Verify if the player truly wants to quit, ex, `Are you sure you want to quit? [Yes], [No]`.


## Class Diagram
 > ![image](https://github.com/cs100/final-project-ncha007-jzhan591-akanc003-jwang705/assets/102260019/1c133fb9-161a-4c14-ada4-55686e68068a)

 The SOLID principle that was applied was the Open-Closed Principle(OCP). This was applied by making the chooseStats and chooseClass classes into functions for the Character class. This helps make the code more manageable and organized so its easier to write and keep track of while doing changes.
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
