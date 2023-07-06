import sys

class Punic:
    def __init__(self):
        self.tests = 0
        self.failures = 0
        self.exiting = False
        self.failedAction = None
        self.passedAction = None
        self.failedAllAction = None
        self.passedAllAction = None

    def __del__(self):
        self.summary()

    def assert_(self, assertion, function, named="Unnamed"):
        self.tests += 1
        result = function()
        testResult = result == assertion

        print(f"Test <{named}> #{self.tests} : {'PASSED' if testResult else 'FAILED'}")

        if not testResult:
            self.failures += 1
            print("  - Expected:", assertion)
            print("  - Actual:  ", result)
            if self.failedAction:
                self.failedAction()
        else:
            if self.passedAction:
                self.passedAction()

        if not testResult and self.exiting:
            print("Test failure. Exiting the program.")
            sys.exit(1)

        return testResult

    def exit_on_failure(self, on_exit):
        self.exiting = on_exit

    def when_failed(self, action):
        self.failedAction = action

    def when_passed(self, action):
        self.passedAction = action

    def when_all_failed(self, action):
        self.failedAllAction = action

    def when_all_passed(self, action):
        self.passedAllAction = action

    def summary(self):
        if self.failures == 0:
            print("All tests passed.")
            if self.passedAllAction:
                self.passedAllAction()
        else:
            print(f"Tests passed with {self.failures} fail(s).")
        if self.failures == self.tests:
            if self.failedAllAction:
                self.failedAllAction()
