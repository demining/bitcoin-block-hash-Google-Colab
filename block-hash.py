import binascii, hashlib, locale, sys

try:
    # Python 3
    block = sys.stdin.buffer.read(80)
except AttributeError:
    # Python 2
    block = sys.stdin.read(80)

if len(block) != 80:
    raise IOError("Could not read block header")

ctx = hashlib.sha256()
ctx.update(block)
hash = ctx.digest()

ctx = hashlib.sha256()
ctx.update(hash)
hash = ctx.digest()

# binascii.hexlify returns bytes, decode for Python 3
print(binascii.hexlify(hash[::-1]).decode(locale.getpreferredencoding()))
