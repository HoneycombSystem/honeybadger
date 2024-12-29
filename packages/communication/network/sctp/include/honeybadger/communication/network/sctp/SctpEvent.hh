#pragma once
#include <cstdint>

namespace honeybadger::communication::network
{
enum class SctpAssociationEventType : std::uint32_t
{
    AssociationUp,
    AssociationLost,
    AssociationRestart,
    ShutdownComplete,
    CannotStartAssociation,
    MaxAssociationEvent
};

enum class SctpPeerAddressChangeEventType : std::uint32_t
{
    AddressAvailable,
    AddressUnreachable,
    AddressRemoved,
    AddressAdded,
    AddressMadePrimary,
    AddressConfirmed,
    AddressPotentiallyFailed,
    MaxPeerAddressChangeEvent
};
}