#include "ZeroDevice.h"
#include "Limits.h"
#include <AK/StdLib.h>
#include <AK/kstdio.h>

ZeroDevice::ZeroDevice()
    : CharacterDevice(1, 5)
{
}

ZeroDevice::~ZeroDevice()
{
}

bool ZeroDevice::hasDataAvailableForRead() const
{
    return true;
}

ssize_t ZeroDevice::read(byte* buffer, size_t bufferSize)
{
    size_t count = min(GoodBufferSize, bufferSize);
    memset(buffer, 0, count);
    return count;
}

ssize_t ZeroDevice::write(const byte*, size_t bufferSize)
{
    return min(GoodBufferSize, bufferSize);
}

