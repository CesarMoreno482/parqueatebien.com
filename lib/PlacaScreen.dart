// ignore_for_file: file_names

import 'package:flutter/material.dart';
import 'dart:convert';
import 'ReportScreen.dart';
import 'package:web/map.dart';
import 'package:geocoding/geocoding.dart';

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

  const PlacaScreen({
    super.key,
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
      appBar: AppBar(),
      body: SingleChildScrollView(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Padding(
              padding: const EdgeInsets.only(top: 20.0),
              child: Center(
                child: Image.asset(
                  'assets/image/LOGO_PARQUEATE.png',
                  height: 75,
                  fit: BoxFit.cover,
                ),
              ),
            ),
            const SizedBox(height: 18.0),
            Container(
              height: 40,
              width: double.infinity,
              padding: const EdgeInsets.all(8.0),
              decoration: const BoxDecoration(
                color: Color.fromARGB(255, 243, 243, 243),
              ),
              child: const Text(
                'DATOS DEL VEHÍCULO',
                textAlign: TextAlign.center,
                style: TextStyle(
                  fontSize: 20,
                  fontWeight: FontWeight.bold,
                  color: Color(0xFF010F56),
                ),
              ),
            ),
            const SizedBox(height: 16.0),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                ElevatedButton(
                  onPressed: () {},
                  style: ElevatedButton.styleFrom(
                    backgroundColor: _getButtonColor(status),
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(20.0),
                    ),
                    padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
                  ),
                  child: Text(
                    'Vehículo $status',
                    style: const TextStyle(color: Colors.white),
                  ),
                ),
                const SizedBox(width: 265.0),
                OutlinedButton.icon(
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
                  icon: const Icon(Icons.info, color: Color(0xFF010F56)),
                  label: const Text(
                    'Más información',
                    style: TextStyle(color: Color(0xFF010F56)),
                  ),
                  style: OutlinedButton.styleFrom(
                    side: const BorderSide(color: Color(0xFF010F56)),
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(10.0),
                    ),
                    padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
                  ),
                ),
              ],
            ),
            const SizedBox(height: 25.0),
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 15.0),
              child: Wrap(
                alignment: WrapAlignment.center,
                spacing: 20.0,
                runSpacing: 20.0,
                children: [
                  _buildInfoColumn('Número de placa', licensePlate),
                  _buildInfoColumn('Tipo de vehículo', vehicleType),
                  _buildInfoColumn('Color', vehicleColor),
                  _buildInfoColumn('Modelo', model),
                  _buildInfoColumn('Año', year),
                  _buildInfoColumn('Referencia', reference),
                ],
              ),
            ),
            const SizedBox(height: 20.0),
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 15.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  const Padding(
                    padding: EdgeInsets.only(left: 10.0),
                    child: Text(
                      'Ubicación de la retención',
                      style: TextStyle(
                        fontSize: 18,
                        fontWeight: FontWeight.bold,
                        color: Color(0xFF010F56),
                      ),
                      textAlign: TextAlign.left,
                    ),
                  ),
                  const SizedBox(height: 10.0),
                  FutureBuilder<String>(
                    future: _getAddressFromLatLon(lat, lon),
                    builder: (context, snapshot) {
                      if (snapshot.connectionState == ConnectionState.waiting) {
                        return const CircularProgressIndicator();
                      } else if (snapshot.hasError) {
                        return const Text('Error al obtener la dirección');
                      } else {
                        return Padding(
                          padding: const EdgeInsets.symmetric(horizontal: 10.0),
                          child: Text(
                            snapshot.data ?? 'Dirección no disponible',
                            style: const TextStyle(fontSize: 16),
                            textAlign: TextAlign.center,
                          ),
                        );
                      }
                    },
                  ),
                  const SizedBox(height: 10.0),
                  SizedBox(
                    height: 150,
                    width: 625,
                    child: MapWidget(
                      destinationLat: lat,
                      destinationLon: lon,
                    ),
                  ),
                ],
              ),
            ),
            const SizedBox(height: 20.0),
            if (photos.isNotEmpty) ...[
              Container(
                padding: const EdgeInsets.symmetric(horizontal: 20.0),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    const Padding(
                      padding: EdgeInsets.symmetric(horizontal: 10.0),
                      child: Text(
                        'Fotos del vehículo',
                        style: TextStyle(
                          fontSize: 18,
                          fontWeight: FontWeight.bold,
                          color: Color(0xFF010F56),
                        ),
                        textAlign: TextAlign.left,
                      ),
                    ),
                    const SizedBox(height: 10.0),
                    Wrap(
                      alignment: WrapAlignment.start,
                      spacing: 8.0,
                      runSpacing: 8.0,
                      children: photos.map((photo) {
                        return SizedBox(
                          width: 115,
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
                ),
              ),
            ],
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {},
        child: Icon(Icons.chat),
        backgroundColor: Colors.blue,
      ),
    );
  }

  Widget _buildInfoColumn(String label, String value) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(
          label,
          style: const TextStyle(
            fontSize: 16,
            fontWeight: FontWeight.bold,
            color: Color(0xFF010F56),
          ),
        ),
        const SizedBox(height: 8.0),
        Text(
          value,
          style: const TextStyle(fontSize: 16),
        ),
      ],
    );
  }

  Future<String> _getAddressFromLatLon(double lat, double lon) async {
    try {
      List<Placemark> placemarks = await placemarkFromCoordinates(lat, lon);
      if (placemarks.isNotEmpty) {
        Placemark placemark = placemarks.first;
        return '${placemark.street}, ${placemark.locality}, ${placemark.postalCode}, ${placemark.country}';
      }
    } catch (e) {
      print('Error al obtener la dirección: $e');
    }
    return 'Dirección no disponible';
  }
}
