# simd-native

https://github.com/holepunchto/libsimd JavaScript bindings for Node.js.

```sh
npm install simd-native
```

## Usage

```js
const { cnt } = require('simd-native')

cnt(Buffer.alloc(16, 0xff))
// <Buffer 08 08 08 08 08 08 08 08 08 08 08 08 08 08 08 08>
```

## API

The lane width of all APIs is determined by the input buffer. That is, if providing a `Uint8Array` the lane width will be 8 bits, if providing a `Uint16Array` the lane width will be 16 bits and so on.

#### `const result = clo(buffer[, result])`

Count the number of leading ones of each 16 byte vector in `buffer`, storing the result in `result`. If `result` is not provided, a fresh buffer is allocated. The `result` buffer is returned to the caller.

#### `const result = clz(buffer[, result])`

Count the number of leading zeroes of each 16 byte vector in `buffer`, storing the result in `result`. If `result` is not provided, a fresh buffer is allocated. The `result` buffer is returned to the caller.

#### `const result = cnt(buffer[, result])`

Compute the population count of each 16 byte vector in `buffer`, storing the result in `result`. If `result` is not provided, a fresh buffer is allocated. The `result` buffer is returned to the caller.

#### `const result = cto(buffer[, result])`

Count the number of trailing ones of each 16 byte vector in `buffer`, storing the result in `result`. If `result` is not provided, a fresh buffer is allocated. The `result` buffer is returned to the caller.

#### `const result = ctz(buffer[, result])`

Count the number of trailing zeroes of each 16 byte vector in `buffer`, storing the result in `result`. If `result` is not provided, a fresh buffer is allocated. The `result` buffer is returned to the caller.

#### `const result = not(buffer[, result])`

Compute the bitwise NOT of each 16 byte vector in `buffer`, storing the result in `result`. If `result` is not provided, a fresh buffer is allocated. The `result` buffer is returned to the caller.

## License

ISC
