# ntl

**ntl** is very tiny and selective implementation of C++ Standard Library (which is sometimes mistakenly called STL) for Windows NT kernel mode drivers.

The name comes from combining **NT** and S**TL**.

## Tests

Tests are done in user-mode using Microsoft's VisualStudio C++ Unit Test Framework.

## Implemented functionality

### [&lt;algorithm&gt;](https://en.cppreference.com/w/cpp/header/algorithm)

#### Comparison operations

- `equal`;
- `lexicographical_compare`;

### [&lt;type_traits&gt;](https://en.cppreference.com/w/cpp/header/type_traits)

#### Classes

##### Helper classes

- `integral_constant`;
- `bool_constant`;
- `true_type`;
- `false_type`;

##### Primary type categories

- `is_class` (as `is_union` is not implemented, it doesn't detect unions);
- `is_pointer`;
- `is_lvalue_reference`(`_v`);

##### Const-volatility specifiers

- `remove_const`(`_t`);
- `remove_volatile`(`_t`);
- `remove_cv`(`_t`);

##### Type relationships

- `is_same`(`_v`);
- `is_base_of`(`_v`);

##### References

- `remove_reference`(`_t`);
- `add_lvalue_reference`(`_t`);
- `add_rvalue_reference`(`_t`);

##### Miscellaneous transformations

- `enable_if`(`_t`);
- `conditional`(`_t`);
- `void_t`;

### [&lt;utility&gt;](https://en.cppreference.com/w/cpp/header/utility)

#### Functions

- `swap`;
- `forward`;
- `move`;

### [&lt;vector&gt;](https://en.cppreference.com/w/cpp/container/vector)

#### Member functions

- `(constructor)`;
- `(destructor)`;
- `operator=`;
- `assign`;

##### Element access

- `at`;
- `operator[]`;
- `front`;
- `back`;
- `data`;

##### Iterators

- `begin` / `cbegin`;
- `end` / `cend`;
- `rbegin` / `crbegin`;
- `rend` / `crend`;

##### Capacity

- `empty`;
- `size`;
- `reserve`;
- `capacity`;
- `shrink_to_fit`;

##### Modifiers

- `clear`;
- `insert`;
- `emplace`;
- `erase`;
- `push_back`;
- `emplace_back`;
- `pop_back`;
- `resize`;
- `swap`;

#### Non-member functions

- `operator==`;
- `operator!=`;
- `operator<`;
- `operator<=`;
- `operator>`;
- `operator>=`;
