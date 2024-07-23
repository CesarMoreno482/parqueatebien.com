import 'package:flutter/material.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';

class MapWidget extends StatelessWidget {
  final double destinationLat;
  final double destinationLon;

  const MapWidget({
    super.key,
    required this.destinationLat,
    required this.destinationLon,
  });

  @override
  Widget build(BuildContext context) {
    return GoogleMap(
      initialCameraPosition: CameraPosition(
        target: LatLng(destinationLat, destinationLon),
        zoom: 13.0,
      ),
      markers: {
        Marker(
          markerId: const MarkerId('destination'),
          position: LatLng(destinationLat, destinationLon),
          infoWindow: const InfoWindow(
            title: 'Destino',
            snippet: 'Aquí está el destino',
          ),
        ),
      },
      onMapCreated: (controller) {
        // Aquí puedes realizar acciones adicionales cuando se crea el mapa
        // Por ejemplo, añadir interactividad con el mapa
      },
    );
  }
}