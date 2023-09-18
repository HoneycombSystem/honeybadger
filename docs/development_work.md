# Development work
This file describes the process of developing the project. Create and split theme into epics and features.

## Main stages of development
### Theme
Themes are the highest level of organization in a project. They are typically used to represent broad initiatives that you are working on. Themes are often used to group epics, which are then used to group user stories.

#### Example
Addition of communication function in the application.

### Epics
Epics are large bodies of work that can be broken down into a number of smaller tasks (called stories). For example, overhauling the user interface of a website would be an epic that you could break down into stories for each page or each major web UI element.

#### Example
Implementation of Private Messaging

### Feature
Features are a group of user stories that deliver value to the customer. They are the smallest unit of work that you can use to demonstrate value to your customers. Features are also the most common way to organize work within a release.

#### Example
Sending Private Messages

### User story
A user story is a tool used in Agile software development to capture a description of a software feature from an end-user perspective. The user story describes the type of user, what they want and why. A user story helps to create a simplified description of a requirement.

#### Example
```gherkin
As a <type of user>, I want <some goal> so that <some reason>.
```
As a registered user, I want to be able to send a private message to another user to communicate privately with them.

### Task
A task is a unit of work that, when performed, contributes to the completion of a larger job. A task can be broken down into assignments for individuals, but ideally it should be a sufficiently small job that it can be accomplished within a few days or weeks.

#### Example
Example of a task for the user story above:
* Create a form for sending messages.
* Create a form for displaying messages.
* Create a database table for storing messages.
* Create a function for sending messages.

#### Example of Acceptance Criteria
Is not necessary to write acceptance criteria for each task. But it is necessary to write acceptance criteria for each user story.

##### Given
* I am a registered user.
##### When
* I click on the "Send Message" button.
* I enter the recipient's username.
* I enter the message text.
* I click on the "Send" button.
##### Then
* The message is sent to the recipient.
* The message is displayed in the recipient's inbox.
* The message is displayed in the sender's outbox.

## Development process
### 1. Create a theme
* The theme name **MUST** be added into the file `docs/themes/themes.md` with short description.
* The theme **MUST** be described in the file `docs/themes/<theme_name>/theme.md`.
* The theme **MUST** be described a problem that it solves.
* The theme **SHOULD** be described in the present tense.
* The theme **SHOULD** be described in the active voice.
* The theme **SHOULD** be described in the third person.
* The theme **MUST** be described what problem it solves.
* The theme **MUST** be described what value it brings to the project.
* The theme **MUST** be described what value it brings to the user.

### 2. Create an epic
* The epic name **MUST** be added into the file `docs/themes/<theme_name>/epics.md` with short description.
* The epic **MUST** be described in the file `docs/themes/<theme_name>/<epic_name>/epic.md`.
* The epic **MUST** be described a problem that it solves.
* The epic **SHOULD** be described in the present tense.
* The epic **SHOULD** be described in the active voice.
* The epic **SHOULD** be described in the third person.

### 3. Create a feature
* The feature name **MUST** be added into the file `docs/themes/<theme_name>/<epic_name>/features.md` with short description.
* The feature **MUST** be described in the file `docs/themes/<theme_name>/<epic_name>/<feature_name>/feature.md`.
* The feature **MUST** be described a problem that it solves.
* The feature **SHOULD** be described in the present tense.
* The feature **SHOULD** be described in the active voice.
* The feature **SHOULD** be described in the third person.

### 4. Create a user story
* The user story name **MUST** be added into the file `docs/themes/<theme_name>/<epic_name>/<feature_name>/user_stories.md` with short description.
* The user story **MUST** be described in the file `docs/themes/<theme_name>/<epic_name>/<feature_name>/<user_story_name>/user_story.md`.
* The user story **MUST** be described a problem that it solves.
* The user story **SHOULD** be described in the present tense.
* The user story **SHOULD** be described in the active voice.
* The user story **SHOULD** be described in the third person.

### 5. Create a acceptance criteria
* The acceptance criteria **MUST** be described in the file `docs/themes/<theme_name>/<epic_name>/<feature_name>/<user_story_name>/acceptance_criteria.md`.

### 6. Create a task
* The task name **MUST** be added into github issues with short description.
