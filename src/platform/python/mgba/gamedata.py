try:
    import mgba_gamedata
except ImportError:
    pass


def search(core):
    crc32 = None
    if hasattr(core, 'PLATFORM_GBA') and core.platform == core.PLATFORM_GBA:
        platform = 'GBA'
        crc32 = core.crc32
    if hasattr(core, 'PLATFORM_GB') and core.platform == core.PLATFORM_GB:
        platform = 'GB'
        crc32 = core.crc32
    cls = mgba_gamedata.registry.search(platform, {'crc32': crc32})
    if not cls:
        return None
    return cls(core.memory.u8)
