#!/usr/bin/env python

import unittest
from testing import div

class TestDiv(unittest.TestCase):

    def test_success(self):
        self.assertEqual(div(10, 2), 5)

    def test_bad_input_error(self):
        pass
    def test_zero_division_error(self):
        self.assertRaises(ZeroDivisionError,div, 10, 0)
        


if __name__ == '__main__':
    unittest.main()
