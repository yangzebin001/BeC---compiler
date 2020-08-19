
### register allocation
- Expression's result store -> r3
- ReturnStatement's result store r3 -> r0
- Functioncall's result store r0 -> r3
- global var 's result store -> r2
- local var 's result store -> r3 and r8
- array decl -> r2
- assign array base -> r1
- array scale -> r9
- function param {r0, r3}

- r6 temp register
- r7 param temp register

### look up variable path:
local scope -> local const -> fathers scope -> fathers const -> global var -> global const