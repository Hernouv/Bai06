# Branch Protection Rules Setup Guide

This guide explains how to configure GitHub Branch Protection Rules to ensure code quality by preventing merges when CI checks fail.

## Overview

Branch Protection Rules ensure that:
- Pull Requests must pass all CI checks before merging
- The merge button is disabled when Checkstyle or Test failures occur
- Code reviews are enforced automatically

## Setup Instructions

### Step 1: Navigate to Repository Settings

1. Go to your GitHub repository
2. Click on **Settings** tab
3. In the left sidebar, click on **Branches** under "Code and automation"

### Step 2: Add Branch Protection Rule for Main Branch

1. Click **Add rule** button
2. In **Branch name pattern**, enter: `main`
3. Click **Configure rule** (or **Create rule**)

### Step 3: Configure Protection Settings

Enable the following settings:

#### Required Status Checks
- ✅ **Require status checks to pass before merging**
- ✅ **Require branches to be up to date before merging**

Add these required status checks:
- `checkstyle` (from Checkstyle job)
- `Build and Test on ubuntu-latest` (from build job)
- `Build and Test on windows-latest` (from build job)
- `Build and Test on macos-latest` (from build job)

#### Additional Protection Rules
- ✅ **Do not allow bypassing the above settings**
- ✅ **Require pull request reviews before merging** (optional but recommended)
  - Set **Required approving reviews** to at least 1
- ✅ **Require conversation resolution before merging** (optional)
- ✅ **Require branches to be up to date before merging**

#### Restrict who can push
- ✅ **Restrict who can push to matching branches**
  - Add only trusted users/teams who should have direct push access

### Step 4: Save the Rule

Click **Create** or **Save changes** to apply the branch protection rule.

## Verification

After setting up branch protection:

1. Create a new branch: `git checkout -b test-branch-protection`
2. Make a change that violates Checkstyle (e.g., add a line longer than 120 characters)
3. Commit and push: `git push origin test-branch-protection`
4. Create a Pull Request to `main`
5. **Expected behavior:**
   - The Checkstyle job should fail
   - The merge button should be disabled/grayed out
   - You should see inline comments from the Checkstyle bot on the violating lines
   - The PR cannot be merged until all checks pass

## How It Works

### Automated Code Review Flow

1. **Developer creates PR** → Triggers CI workflow
2. **Checkstyle job runs** → Analyzes code style violations
3. **Checkstyle PR Reviewer action** → Posts inline comments on violating lines
4. **Build job runs** → Executes tests and coverage checks
5. **Branch Protection** → Blocks merge if any check fails
6. **Developer fixes issues** → Updates PR
7. **All checks pass** → Merge button becomes enabled

### Checkstyle Violation Types

The current `checkstyle.xml` configuration enforces:
- Line length ≤ 120 characters
- Proper naming conventions (camelCase, PascalCase, etc.)
- No unused imports
- No magic numbers (except -1, 0, 1, 2)
- Proper whitespace around operators
- Missing braces for control structures
- And many more code quality rules

## Troubleshooting

### Merge Button Still Enabled When Checks Fail

- Verify that the required status checks are correctly listed in branch protection
- Ensure the workflow names match exactly (case-sensitive)
- Check that the workflow has run at least once on the branch

### Checkstyle Comments Not Appearing

- Verify that `GITHUB_TOKEN` has proper permissions (should be automatic)
- Check that the PR is targeting a protected branch (main, master, or develop)
- Ensure the Checkstyle job is running and completing

### Workflow Not Triggering on PR

- Verify the workflow file is in `.github/workflows/` directory
- Check that the PR targets the correct branches (main, master, develop)
- Ensure the workflow YAML syntax is valid

## Additional Resources

- [GitHub Branch Protection Documentation](https://docs.github.com/en/repositories/configuring-branches-and-merges-in-your-repository/managing-protected-branches/about-protected-branches)
- [Checkstyle Documentation](https://checkstyle.org/)
- [GitHub Actions Documentation](https://docs.github.com/en/actions)
