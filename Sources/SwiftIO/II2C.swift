//=== II2C.swift -----------------------------------------------------------===//
//
// Copyright (c) MadMachine Limited
// Licensed under MIT License
//
// Authors: Jan Anstipp
// Created: 09/18/2021
//
// See https://madmachine.io for more information
//
//===----------------------------------------------------------------------===//

public protocol II2C {
    
    /**
     Initializes a specific I2C interface as a master device.

     > Note: Please make sure the communication speed set for the I2C is supported
     by the slave device.

     - Parameter idName: **REQUIRED** The name of I2C pin. See Id for the board in
     [MadBoards](https://github.com/madmachineio/MadBoards) library for reference.
     - Parameter speed: **OPTIONAL** The clock speed for data transmission,
     standard (100 Kbps) by default.

     */
    init(_ idName: IdName, speed: I2CSpeed)
    
    /**
     Gets the current clock speed of the data transmission.
     
     - Returns: The current speed: `.standard` (100 Kbps), `.fast` (400 Kbps) or `.fastPlus` (1Mbps).
     */
    func getSpeed() -> I2CSpeed
    
    /**
     Sets the clock speed to change the transmission rate.
     - Parameter speed: The clock speed for data transmission:
     `.standard` (100 Kbps), `.fast` (400 Kbps) or `.fastPlus` (1Mbps).
     */
    func setSpeed(_ speed: I2CSpeed) -> Result<(), Errno>

     /// Reads a byte from the specified slave device with the given address.
     /// - Parameters:
     ///   - byte: A UInt8 variable to store the received data.
     ///   - address: The address of the slave device to communicate with.
     /// - Returns: Whether the communication succeeds. If not, it returns the
     /// specific error.
    @discardableResult
    func read(into byte: inout UInt8, from address: UInt8 ) -> Result<(), Errno>

     /// Reads bytes from the specified slave device with the given address and
     /// store them in the buffer.
     /// - Parameters:
     ///   - buffer: An array to store the received data.
     ///   - count: The number of data to read. Make sure it doesn’t exceed the
     ///   length of the `buffer`. If it's nil, it equals the length of the `buffer`.
     ///   - address: The address of the slave device to communicate with.
     /// - Returns: Whether the communication succeeds. If not, it returns the
     /// specific error.
    @discardableResult
    func read( into buffer: inout [UInt8], count: Int?, from address: UInt8 ) -> Result<(), Errno>

     /// Writes a UInt8 to the specified slave device with the given address.
     /// - Parameters:
     ///   - byte: A UInt8 to be sent to the slave device.
     ///   - address: The address of the slave device to communicate with.
     /// - Returns: Whether the communication succeeds. If not, it returns the
     /// specific error.
     @discardableResult
    func write(_ byte: UInt8, to address: UInt8) -> Result<(), Errno>

     /// Writes an array of UInt8 to the specified slave device with the given address.
     /// - Parameters:
     ///   - data: An array of UInt8 to be sent to the slave device.
     ///   - count: The number of elements in `data` to be sent. Make sure it
     ///   doesn’t exceed the length of the `data`. If it's nil, all will be sent.
     ///   - address: The address of the slave device to communicate with.
     /// - Returns: Whether the communication succeeds. If not, it returns the
     /// specific error.
    @discardableResult
    func write(_ data: [UInt8], count: Int?, to address: UInt8) -> Result<(), Errno>

     /// Writes a UInt8 to the specified slave device with the given address and
     /// then read a UInt8 from it.
     ///
     /// > Note: This method is not a simple combination of ``write(_:to:)`` and
     /// ``read(into:from:)`` due to some details of data transmission.
     /// Usually, you can find the info about I2C communication about each device
     /// on its manual.
     /// - Parameters:
     ///   - byte: A UInt8 to be sent to the slave device.
     ///   - buffer: A UInt8 variable to store the received data.
     ///   - address: The address of the slave device to communicate with.
     /// - Returns: Whether the communication succeeds. If not, it returns the specific error.
    @discardableResult
    func writeRead(
        _ byte: UInt8,
        into buffer: inout UInt8,
        address: UInt8
    ) -> Result<(), Errno>

     /// Writes a UInt8 to the specified slave device with the given address and
     /// then read bytes from it.
     ///
     /// > Note: This method is not a simple combination of ``write(_:to:)`` and
     /// ``read(into:count:from:)`` due to some details of data transmission.
     /// Usually, you can find the info about I2C communication about each device
     /// on its manual.
     /// - Parameters:
     ///   - byte: A UInt8 to be sent to the slave device.
     ///   - buffer: A UInt8 array to store the received bytes.
     ///   - readCount: The number of bytes to read. Make sure it doesn’t exceed
     ///   the length of the `buffer`. If it’s nil, it equals the length of the `buffer`.
     ///   - address: The address of the slave device to communicate with.
     /// - Returns: Whether the communication succeeds. If not, it returns the specific error.
     @discardableResult
    func writeRead(
        _ byte: UInt8,
        into buffer: inout [UInt8],
        readCount: Int? ,
        address: UInt8
    ) -> Result<(), Errno>

     /// Writes an array of UInt8 to the slave device with the given address and
     /// then read bytes from it.
     ///
     /// > Note: This method is not a simple combination of ``write(_:count:to:)``
     /// and ``read(into:count:from:)`` due to some details of data transmission.
     /// Usually, you can find the info about I2C communication about each device
     /// on its manual.
     /// - Parameters:
     ///   - data: An array of UInt8 to be sent to the slave device.
     ///   - writeCount: The number of elements in `data` to be sent. Make sure
     ///   it doesn’t exceed the length of the `data`. If it’s nil, all will be sent.
     ///   - buffer: A UInt8 array to store the received bytes.
     ///   - readCount: The number of bytes to read. Make sure it doesn’t exceed
     ///   the length of the `buffer`. If it’s nil, it equals the length of the `buffer`.
     ///   - address: The address of the slave device to communicate with.
     /// - Returns: Whether the communication succeeds. If not, it returns the
     /// specific error.
     @discardableResult
    func writeRead(
        _ data: [UInt8],
        writeCount: Int?,
        into buffer: inout [UInt8],
        readCount: Int?,
        address: UInt8
    ) -> Result<(), Errno>

}

/**
 The clock speed settings used to synchronize the data transmission between
 devices.
 */
public enum I2CSpeed {
    /// 100 Kbps
    case standard
    /// 400 Kbps
    case fast
    /// 1 Mbps
    case fastPlus
}
