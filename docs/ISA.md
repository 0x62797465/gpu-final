Each instruction must have a width of a multiple of 8

INT32: 
ADD   rd, rs1, rs2/imm - rd = rs1 + rs2/imm
SUB   rd, rs1, rs2/imm - rd = rs1 - rs2/imm
XOR   rd, rs1, rs2/imm - rd = rs1 ^ rs2/imm
OR    rd, rs1, rs2/imm - rd = rs1 | rs2/imm
AND   rd, rs1, rs2/imm - rd = rs1 & rs2/imm
SLL   rd, rs1, rs2/imm - rd = rs1 << rs2/imm
SRL   rd, rs1, rs2/imm - rd = rs1 >> rs2/imm (zero fill)
SRA   rd, rs1, rs2/imm - rd = rs1 >> rs2/imm (rs1's sign is extended)
// comparisons
SLT   rd, rs1, rs2/imm - rd = (rs1 < rs2/imm)?1:0
SLTU  rd, rs1, rs2/imm - rd = (rs1 < rs2/imm)?1:0 *unsigned
SET   rd, rs1, rs2/imm - rd = (rs1 == rs2/imm)?1:0
SNET  rd, rs1, rs2/imm - rd = (rs1 != rs2/imm)?1:0

FP32:
FMADD  rd, rs1, rs2, rs3 - rd = rs1 * rs2 + rs3
FMSUB  rd, rs1, rs2, rs3 - rd = rs1 * rs2 - rs3
FNMADD rd, rs1, rs2, rs3 - rd = -rs1 * rs2 + rs3
FNMSUB rd, rs1, rs2, rs3 - rd = -rs1 * rs2 - rs3
FADD   rd, rs1, rs2      - rd = rs1 + rs2
FSUB   rd, rs1, rs2      - rd = rs1 - rs2
FMUL   rd, rs1, rs2      - rd = rs1 * rs2
// comparisons
FSLT   rd, rs1, rs2/imm  - rd = (rs1 < rs2/imm)?1:0
FSET   rd, rs1, rs2/imm  - rd = (rs1 == rs2/imm)?1:0
FSNET  rd, rs1, rs2/imm  - rd = (rs1 != rs2/imm)?1:0

Special:
FRCP  rd, rs1 - rd = 1/rs1.f
FSQRT rd, rs1 - rd = rs1.f^(1/2)
SIN   rd, rs1 - rd = sin(rs1.f)
COS   rd, rs1 - rd = cos(rs1.f)
POPC  rd, rs1 - rd = popcount(rs1)

Addressing is relative to the memory for each thread/block. Global memory accesses are not. All instructions zero extend, must be 8 bit alligned. 
Memory:
// Loads memory into the resulting register
LD.l.<u8, u16, u32> rd, rs1 // thread level (local)
LD.b.<u8, u16, u32> rd, rs1 // block level
LD.g.<u8, u16, u32> rd, rs1 // global
// Stores data into the memory at rs1
ST.l.<u8, u16, u32> rs1, rs2 // thread level (local)
ST.b.<u8, u16, u32> rs1, rs2 // block level
ST.g.<u8, u16, u32> rs1, rs2 // global

Format:
[     63:38       ][                37:32           ][  31:27 ][ 26:21][20:15][14:9 ][ 8:4][      3:0        ]
[immediate/address][width & type information/rs3/imm][reserved][  rd  ][ rs1 ][ rs2 ][ op ][hardware resource]