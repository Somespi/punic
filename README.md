# Punic

Punic is a lightweight and user-friendly unit testing framework for Python. It provides an easy and efficient way to write and execute tests for your Python code.

## Features

- **Easy Integration:** Punic can be easily integrated into your Python projects.

- **Simple Assertion:** The framework provides an `assert_` method for making assertions on expected and actual values.

- **Output Formatting:** Test results are displayed in a clear and readable format.

- **Customizable:** Punic is flexible and customizable to suit your specific requirements.

## Getting Started

1. Install Punic: `pip install punictest`

2. Write your tests using the `assert_` method:

```python
from punictest import Punic

p = Punic()
p.assert_(4, lambda: 2 + 2, "Addition")

``` 

3. Run your test program.


## Reference

The Punic class provides methods for defining and executing tests, configuring behavior, and callbacks:

`assert_(assertion, function, named="Unnamed")`: Defines a test case.

`exit_on_failure(on_exit)`: Configures whether the program should exit on a test failure.

`when_failed(action)`: Sets a callback function to be executed when a test case fails.

`when_passed(action)`: Sets a callback function to be executed when a test case passes.

## Contributions
Contributions to Punic are welcome! Please open an issue or submit a pull request for bug fixes, new features, or enhancements.

## License
Punic is released under the MIT License. See the LICENSE file for more details.