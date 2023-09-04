# Branch name convention
The project will be developed incrementally, there will be no split into separate features. Each step will be based on a CI/CD. The project will be developed in the `master` branch. Each release **MUST** be tagged with a version number.

## Branch types
### 1. Hotfix branch
The hotfix branch **MUST** be created from the `master` branch. The hotfix branch **MUST** be deleted after merging into the `master` branch.

Hotfix branch should be used only for fixing bugs in the `master` branch.

### Example
```bash
git checkout master # Switch to the master branch
git pull # Update the master branch
git checkout -b hotfix/<issue_number> # Create a hotfix branch
```

### 2. Spike branch
The spike branch **MUST** be created from the `master` branch. The spike branch **MUST** be deleted after merging into the `master` branch.

Spike branch should be used only for research and development.

### Example
```bash
git checkout master # Switch to the master branch
git pull # Update the master branch
git checkout -b spike/<short_description> # Create a spike branch
```

## Example of a branch name

### 1. Hotfix branch
The hotfix branch **MUST** be named only number of the issue.

### Example
```bash
git checkout master # Switch to the master branch
git pull # Update the master branch
git checkout -b hotfix/1 # Create a hotfix branch
```

### 2. Spike branch
The spike branch **MUST** be named in the kebab-case.

### Example
```bash
git checkout master # Switch to the master branch
git pull # Update the master branch
git checkout -b spike/create-a-form-for-sending-messages # Create a spike branch
```