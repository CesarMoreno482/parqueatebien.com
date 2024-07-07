import 'package:flutter/material.dart';
import 'dart:convert';
import 'ReportScreen.dart';
import 'package:web/map.dart';

class PlacaScreen extends StatelessWidget {
  final String registrationNumber;
  final String licensePlate;
  final String registrationDocument;
  final String vehicleType;
  final String vehicleColor;
  final String model;
  final String year;
  final String reference;
  final String status;
  final String reportedDate;
  final dynamic towedByCraneDate;
  final dynamic arrivalAtParkinglot;
  final dynamic releaseDate;
  final double lat;
  final double lon;
  final List<String> photos;

  PlacaScreen({
    required this.registrationNumber,
    required this.licensePlate,
    required this.registrationDocument,
    required this.vehicleType,
    required this.vehicleColor,
    required this.model,
    required this.year,
    required this.reference,
    required this.status,
    required this.reportedDate,
    required this.towedByCraneDate,
    required this.arrivalAtParkinglot,
    required this.releaseDate,
    required this.lat,
    required this.lon,
    required this.photos,
  });

  Color _getButtonColor(String status) {
    switch (status.toLowerCase()) {
      case 'reportado':
        return Colors.grey;
      case 'retenido':
        return Colors.red;
      case 'liberado':
        return Colors.green;
      case 'incautado por grua':
        return Colors.orange;
      default:
        return Colors.grey;
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Datos del Vehículo'),
      ),
      body: Stack(
        children: [
          SingleChildScrollView(
            padding: const EdgeInsets.all(20.0),
            child: Center(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.center,
                children: [
                  Image.asset(
                    'assets/image/LOGO_PARQUEATE.png',
                    height: 100,
                    fit: BoxFit.cover,
                  ),
                  const SizedBox(height: 16.0),
                  Text(
                    'Datos del Vehículo',
                    style: TextStyle(
                      fontSize: 24,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  const SizedBox(height: 16.0),
                  ElevatedButton(
                    onPressed: () {
                      // Acción del botón
                    },
                    style: ElevatedButton.styleFrom(
                      backgroundColor: _getButtonColor(status),
                    ),
                    child: Text(
                      status,
                      style: TextStyle(color: Colors.white),
                    ),
                  ),
                  const SizedBox(height: 20.0),
                  Row(
                    mainAxisSize: MainAxisSize.min,
                    children: [
                      Text('Más info'),
                      IconButton(
                        icon: Icon(Icons.info),
                        onPressed: () {
                          Navigator.push(
                            context,
                            MaterialPageRoute(
                              builder: (context) => ReportScreen(
                                registrationNumber: registrationNumber,
                                licensePlate: licensePlate,
                                registrationDocument: registrationDocument,
                                vehicleType: vehicleType,
                                vehicleColor: vehicleColor,
                                model: model,
                                year: year,
                                reference: reference,
                                status: status,
                                reportedDate: reportedDate,
                                towedByCraneDate: towedByCraneDate,
                                arrivalAtParkinglot: arrivalAtParkinglot,
                                releaseDate: releaseDate,
                                lat: lat,
                                lon: lon,
                                photos: photos,
                              ),
                            ),
                          );
                        },
                      ),
                    ],
                  ),
                  const SizedBox(height: 20.0),
                  if (status.toLowerCase() != 'liberado') ...[
                    _buildInfoRow('Número de registro', registrationNumber),
                    _buildInfoRow('Número de Placa', licensePlate),
                    _buildInfoRow('Tipo de Vehículo', vehicleType),
                    _buildInfoRow('Color', vehicleColor),
                    _buildInfoRow('Modelo', model),
                    _buildInfoRow('Año', year),
                    _buildInfoRow('Referencia', reference),
                    _buildInfoRow('Ubicación de la Retención', ''),
                    const SizedBox(height: 1.0),
                    Container(
                      height: 200,
                      width: 350,
                      child: MapWidget(
                        destinationLat: lat,
                        destinationLon: lon,
                      ),
                    ),
                    if (photos.isNotEmpty) ...[
                      Text(
                        'Fotos del Vehículo',
                        style: TextStyle(
                          fontSize: 18,
                          fontWeight: FontWeight.bold,
                          color: Color(0xFF010F56),
                        ),
                      ),
                      const SizedBox(height: 8.0),
                      Wrap(
                        spacing: 8.0,
                        runSpacing: 8.0,
                        children: photos.map((photo) {
                          return SizedBox(
                            width: 100,
                            height: 100,
                            child: ClipRRect(
                              borderRadius: BorderRadius.circular(4.0),
                              child: Image.memory(
                                base64Decode(photo),
                                fit: BoxFit.cover,
                              ),
                            ),
                          );
                        }).toList(),
                      ),
                    ],
                  ],
                  const SizedBox(height: 15.0), 
                ],
              ),
            ),
          ),
          Positioned(
            bottom: 20,
            right: 20,
            child: FloatingActionButton(
              onPressed: () {
              
              },
              child: Icon(Icons.chat),
              backgroundColor: Colors.blue,
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildInfoRow(String label, String value) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 8.0),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.center, 
        children: [
          Text(
            label,
            style: TextStyle(
              fontSize: 18,
              fontWeight: FontWeight.bold,
              color: Color(0xFF010F56),
            ),
          ),
          const SizedBox(height: 4.0),
          Text(value, style: TextStyle(fontSize: 18)),
        ],
      ),
    );
  }
}
